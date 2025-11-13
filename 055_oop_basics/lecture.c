//////////// Adım 7 — Strategy / Plugin Pattern (Seçilebilir Davranışlar) //////////////////////////

/*
bu adımda artık elimizde:

kapsüllenmiş (opaque) yapılar ✅

hata kodları ✅

init–destroy yaşam döngüsü ✅

var. şimdi hedefimiz:

aynı arayüzü kullanan ama farklı davranışlar sergileyen birden fazla implementasyon oluşturmak.
bu, gömülü sistemlerde sürücü veya “output backend” tasarlarken çok kullanılır.
*/



// Amaç (Nedir?)

/*
Bir yapının davranışını dışarıdan seçilebilir hale getirmek.
Yani aynı API üzerinden:

biri ekrana yazsın,

biri dosyaya yazsın,

biri UART’a yollasın.

Ama sen logger_write() dediğinde bunların hangisinin çalıştığını bilmeyeceksin.

Bu kalıba Strategy Pattern veya Plugin Pattern denir.
*/


// Neden ihtiyaç duyuldu?

/*
Düşün: sisteminde log basmak istiyorsun ama hedef platforma göre fark değişiyor:

test ortamında printf

gömülüde UART_Send

üretimde write_to_flash

Eğer her yere #ifdef koyarsan proje çorba olur:
*/

#ifdef USE_UART
UART_Send(...)
#elif USE_PRINTF
printf(...)
#endif

// yerine 

logger_set_backend(&uart_logger);
logger_write("Hello");

//ve artık davranışı kolayca değiştir.


// Nasıl çalışır?


/*
1️⃣ Ortak bir arayüz (ör. logger_vtable_t) tanımlanır.
2️⃣ Her “backend” kendi fonksiyonlarını bu tabloya doldurur.
3️⃣ logger_t yapısı sadece o tabloyu (vptr) tutar.
4️⃣ Kullanıcı sadece logger_write() çağırır — altındaki sistem değişebilir.
*/