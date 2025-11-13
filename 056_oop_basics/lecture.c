// ---------------------------- Adım 8 — Mock / Fake ile Test Edilebilir API’ler -------------------------------

// Amaç (Nedir?)

/*
Gerçek donanım veya dosya erişimi olmayan ortamlarda
(modül testleri, simülasyonlar ve PC tarafı testleri gibi)
modülün davranışını taklit ederek test edebilmek.

Yani:

“Gerçek UART’ı değil, onun davranışını benzeten sahte bir nesne kullanayım,
böylece sistemi test edebilirim.”

*/

// Neden ihtiyaç duyuldu?

/*
Gerçek sistemde:
*/

HAL_UART_Transmit(...);   // donanıma bağlı  
fopen("data.txt");        // diske bağlı  
read_sensor();            // ADC'ye bağlı


/*
ama birim testi (unit test) sırasında:

UART yok, dosya yok, sensör yok.

ama kodun mantığını test etmek istiyoruz.

Mock / Fake yapıları sayesinde gerçek yerine geçici (taklit) nesneler ekleriz.
Bu sayede:
- Test edilebilirlik
- Hata senaryosu simülasyonu
- Donanımdan bağımsız mantık doğrulaması sağlanır.
*/

// Nasıl çalışır?
/*
1️⃣ Ortak arayüz oluşturulur (örneğin driver_vtable_t).
2️⃣ Gerçek ve Fake implementasyonlar bu arayüzü uygular.
3️⃣ Üst katman (örneğin app.c) sadece bu arayüzü kullanır.
4️⃣ Test esnasında gerçek nesne yerine fake nesne enjekte edilir.
*/