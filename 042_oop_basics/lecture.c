//////////// adım 2 — callback ve void *user (bağlam) //////////////////////////

// Neden ?

/*
 Bir kütüphane/işlev “olay olduğunda haber versin” isteriz. Olayı işleyen kodun durum tutması gerekebilir.
 void *user ile kullanıcıya ait bağlamı geri göndeririz (RTOS’taki kancalarda da aynı fikir).
*/

// Kavramlar 

/*
callback: Kütüphanenin senin verdiğin fonksiyonu zamanı gelince çağırması.
context / user data: Callback’in kullanacağı, kullanıcıya ait ek bilgi.
opaque pointer: (burada sadece fikir) İçeriğini bilmediğimiz, kullanıcıya ait veri.
*/

#include <stdio.h>

/* 1) Olay bildirimi için imza: kullanıcı bağlamı + kod */
typedef void (*on_event_t)(void *user, int code);

/* 2) Basit bir "zamanlayıcı/çalıştırıcı" taklidi */
typedef struct {
    on_event_t on_event;
    void *user;
} Notifier;

/* 3) Kitaplık tarafı: bir şeyler yapar ve olayı tetikler */
void run_task(Notifier *n) {
    printf("[lib] iş yapıyorum...\n");
    if (n->on_event) {
        n->on_event(n->user, 100); // 100: örnek olay kodu
    }
}

/* 4) Kullanıcı tarafındaki durum (bağlam) */
typedef struct {
    int count;
    const char *name;
} MyCtx;

/* 5) Kullanıcı callback'i: bağlamı geri alır ve kullanır */
void my_handler(void *user, int code) {
    MyCtx *ctx = (MyCtx*)user; // geri cast
    ctx->count++;
    printf("[cb] %s: code=%d, count=%d\n", ctx->name, code, ctx->count);
}

int main(void) {
    MyCtx ctx = { .count = 0, .name = "demo" };

    Notifier n = {
        .on_event = my_handler,
        .user     = &ctx
    };

    run_task(&n);
    run_task(&n);
    run_task(&n);
    return 0;
}

// Çıktı
/*
    [lib] iş yapıyorum...
    [cb] demo: code=100, count=1
    [lib] iş yapıyorum...
    [cb] demo: code=100, count=2
    [lib] iş yapıyorum...
    [cb] demo: code=100, count=3
*/

// Mantık

/*
Kitaplık, “kimin” adına çalıştığını bilmez; sadece on_event ve user’ı saklar, doğru anda geri çağırır. 
user sayesinde hangi örnek üzerinde çalıştığını öğrenir.
*/