// ---- Callback ve Context ---

/* 

bir lib, task'ini tamamladığında user layer'a bir geri bildirimde bulunmak istiyor.
bunun içinde callback'i ve context'i kullanıyor.

-> typedef void (*on_event_td)(*void user, uint8_t event_code)

bu bir callback signature'u 
bir event olduğunda user'ın çağıracağı fonksiyonun signature'u budur diyor.
iki parametre alır :
context  void *user
event_code

-> typedef struct
{
    on_event_td on_event 
    void *user
}

Lib'in kullanıcı bilgilerine ihtiyacı var. Bu yapı onu sağlıyor.
on_event : event olduğunda kullanıcı hangi gonksiyonu çağıracak ? my_handler'ı çağıracak
user     : evetn olduğunda hangi kullanıcının hangi verileri kullanılacak ? my_ctx


->void run_task(notifier_td *n)
{
    printf("[lib]: i do something bla bla..\n");
    if(n->on_event) // i dont understand this line ?
    {
        n->on_event(n->user,EVENT_CODE_ADC);
    }
}

task islerken bir event oldu ve  lib teslimatını yaptı n->user'a dallan ve event kodunu teslim et !
cunku lib, kullanicinin ne yaptigi ile ilgilenmez event kodunu alıcısına teslim eder ve ayrılır.
Yani aslında bakarsak n->user benim my_handler fonksiyonum.
Buradaki if(n->on_event) ise null pointer kontroludur !!!(sakın event flag gibi dusunme)!!!
if(n->on_event) : on_event alanı bir fonksiyonu isaret ediyorsa my_handler'ı çağır
çünkü kullanıcı notifier_td yapısını oluştururken on_event alanına bir fonksiyon atamayabilir, atamazsa NULL pointer !


-> void my_handler(void *user, uint8_t event_code)
{
    my_ctx *ctx = (my_ctx*)user; 
    ctx->count++;
    printf("[callback] %s: code=%d, count%d\n",ctx->name,event_code,ctx->count);
}

a) bağlam (context) saklama
Lib, kullanıcı verisinin tam olarak ne olduğunu bilmek istemez, bilseydi esnek olmazdı.
Bu yüzden notifier_td yapısında benim verimi (yani contextimi) void* tipinde saklıyor.
void*, herhangi bir şeyi işaret eden işaretci

b) back cast
event tetiklendiginde, lib benim my_handler'ımı çağırıyor ve sakladığı void *user adresimi geri veriyor
my_ctx *ctx = (my_ctx*)user; // <-- İşte bu "back cast"
 ... artık ctx->count gibi alanlara erişebilirsin

 Context'im lib'den bana void* olarak gelmişti oysa ki benim yapım my_ctx idi
 lib benim yapımı umursamıyor ki event sonunda my_handler'a dallandırırken bana bir seyin isaretcisi diyip veriyor
 benim bunu tabiri caizse my_handler icinde typecast etmem gerek :D 
 Yani 
 my_ctx *ctx = (my_ctx*)user

 bu casting sayesinde kaybolan tip bilgimi geri alıp, yapımın içindeki count ve name gibi alanlara erişiyorum
 */


 // ----GENEL API DAVRANISI ---

 /* 1) user, ne çağırılacağını ve neyi taşıyacağını bilgisini lib'e verir
                    |                    |
                    v                    v
                my_handler             &ctx


    2) Lib, bu bilgileri önemsemeden saklar ve task işlerken bir event olduğunda
    3) Lib, if(on_event) kontrolü yapar ve eğer bir fonk varsa sakladığı bağlamı ve olay kodunu vererek my_handler'ı çağırır
    4) Callback (benim fonksiyonum) yani my_handler, void* 'i kendi orjinal tipine geri dönüştürür ve verileri gunceller
                                                                          |                              | 
                                                                          v                              v
                                                                        my_ctx*                       count,name

 */