Device-Free Indoor People Counting Using Wi-Fi   Channel State Information for Internet of Things

  Selcan Kebelioðlu, Sinem Ezgi Tutuman , Melike Aydýn, Feyzanur Kuzucu, Ayþe Nur Akman , Yaðmur Çatak
 Bilgisayar Mühendisliði Bölümü(2.Öðretim)
Kocaeli Üniversitesi





Özet

Bu projede amacýmýz Wifi teknolojisini kullanarak ortamda bulunan ,wifi vericisine baðlanan alýcýlarý tespit etmek ve wifi vericisine baðlananan kiþi sayýsýný bulmaktýr.Bu projeyi kullanýcý,müþteri sayýsý belirlemek isteyen yerlerde, acil durum ve afetlerde kiþilerin nerede olduðunu belirlemek amacýyla kullanabiliriz.


1. Giriþ

Kapalý alanlarda insan sayýmý,yoðunluk önemlidir.Trafik yönetimi,yaþlýlarýn izlenmesi,konferansa katýlým sayýsý vb,bilgileri eriþmek için bu uygulama kullanýlmaktadýr.Kablosuz sinyallerle bu problemi çözmek mümkündür.Kablosuz sinyaller kullanlarak kapalý alanda kiþi sayýsýnýn belirlenmesi NodeMCU yardýmýyla mümkün olur.
Wifi gibi kablosuz cihazlar kullanýlarak baþka bir ekipmana gerek duyulmamaktadýr.NodeMCU ile elde edilen veriler Firebase 'e kayýt edilir.Kayýt edilen veriler MIT App Inventor ile arayüze aktarýlýr.


2. Temel Kavramlar
Projemizi geliþtirmek için aþaðýdaki malzemeleri ve ortamlarý kullandýk.




NodeMCU  Ve  ESP 8266 :



                                      Þekil 1.0

Arduino, programlayabildiðimiz bir davre kartýdýr.NodeMCU ise Arduino, Arduino IDE uygulamasýndan programlayabildiðimiz içinde ESP8266 bulunduran bir devre kartýdýr. Programlanabilirdir, düþük maliyetli ve basittir. Ayrýca akýllý bir cihazdýr ve WI-FI baðlantýya yani kablosuz baðlantýya ve kullanýma hazýr gelir.
Özellikleri ;
CPU  : 80MHz(varsayýlan) veya 160MHZ
Bellek :64 KB ,   Wireless Standart : 802.11 b/g/n
GPIO : 16 Pin
Haberleþme Protokolü: SPI,12C,UART
Analog Pin : 10 Bit ADC  ,    Güç : 3.3 VDC

Firebase:

JSON verilerimizi uzak bir sunucuda gerçek zamanlý olarak depolayabildiðimiz, bulut (Cloud) tabanlý bir platformdur. Firebase; sunucu tarafýnda (BackEnd) bize saðlamýþ olduðu servis desteði sayesinde, veri tabanýnda gerçekleþen her deðiþiklikten anýnda haberdar olabilmemizi mümkün kýlmaktadýr. Firebase'de android uygulamasýndan ve ESP'den deðerler saklanýr. Daha sonra bazý fonksiyonlar kullanýlarak deðerlere ESP ve uygulama tarafýndan eriþilir. Bu deðerlere eriþmek için özel kimlik doðrulama anahtarý gerekir.

Donaným platformu olarak Arduino IDE ile programlanan NodeMCU 1.0 Development Board'u (ESP 8266 tabanlý) kullandýk.
Veritabanýný oluþturmak için adýmlar;

1) https://console.firebase.google.com/  sitesinden “get started” butonu yönlendirir.[9]

2) Add Project butonunu seçeriz.


3) Proje ismini girip, proje oluþtururuz.

4) Açýlan sayfadan “database”i seçeriz.


5) Veritabaný seçeneðini seçtikten sonra, bir sonraki sayfada aþaðý kaydýrýp, gerçek zamanlý veritabaný oluþtur öðesini seçip kilitli modda oluþtururuz.

6) GUI'de bulunan küçük artý (+) iþaretlerini kullanarak veritabanýna alt öðeler ekleyebiliyoruz.

7) Herhangi bir cihazýn veritabanýmýza eriþebilmesi için veritabanýnýn kurallarýný deðiþtirmemiz gerekiyor. Bunu yapmak için kurallar sekmesine gidip aþaðýdaki gibi kodu deðiþtiriyoruz.


8) Daha sonra bir proje oluþturuyorup Donaným Platformunu Yapýlandýrýyoruz.
NodeMCU’yu doðru bir þekilde ayarladýktan sonra. WiFi Router'ýmýza / Hotspot'umuza baðlanmak için basit bir kod yükleyerek test edilebilir.

9) Donanýmý Veritabanýna Baðlamak.
Arduino'yu veritabanýna baðlamak için Firebase Arduino Kütüphanesi'ni kullandýk.[9]

MIT  Android uygulamasý:

App Inventor baþlangýçta Google tarafýndan oluþturulan daha sonralarý ise Massachusetts Institute of Technology (MIT) tarafýndan desteklenen açýk kaynaklý(open source) bir web uygulamasýdýr. App Inventor , Türkçe’ye uygulama mucidi olarak çevrilmiþtir. App Inventor yeni baþlayanlar için kolaylýkla Android uygulama geliþtirmesine olanak saðlar. Uygulamamýzda bu yazýlýmý kullandýk.

3. SÝSTEM TASARIMI VE UYGULAMASI 

Öncelikle “http://arduino.esp8266.com/stable/package_esp8266com_index.json” url sini Arduino uygulamasýndan Dosya>Tercihler>Ek Devre Kartý Yöneticisi URL’ri bölüme yazýyoruz.
Kart>KartYöneticisi>Aramalarýnýzý Filtreleyin>ESP8266 yazýp çýkan þeyi indiriyoruz. Böylece nodeMCU kartýný aktifleþtirmiþ oluyoruz.

                             Þekil 1.1

Projemizde ESP 8266'yý wifi modülü olarak kullandýk.  ESP 8266 da Wifi kullanýcýnýn baðlanacaðý baðlantý adýmýzý ve þifremizi belirledik.Ardýndan sonuç deðiþkeninde wifi parola ve þifresi uyan cihazlarý kontrol ederek sayýsýný ve IP adresini ekrana yazdýrdýk.Firebase kütüphanesini Arduino 'a ekleyerek bulduðumuz verileri (kullanýcý IP adresleri ve kiþi sayýsý) Firebase veritabanýna kaydettik.Kaydedilen verileri MIT App Ýnventorda bir arayüz oluþturarak kullanýcý arayüzünü oluþturmuþ olduk.
Kodumuzu inceleyecek olursak;

Öncelikle #include <ESP8266WiFi.h>
#include <FirebaseArduino.h> kütüphanelerimizi tanýmlarýz.
Ardýndan wifi adýný ve pasaport adýný tanýmlarýz.Wifi adresimiz ve pasaportumuz bu tanýmlanan veriler olacaktýr. #define FIREBASE_HOST "deneme-eb804.firebaseio.com" þeklinde firebasedeki proje adlarýmýzý ve baðlantýyý saðlamak için gerekli þifreyi tanýmlarýz.
Setup() fonksiyonu içinde WiFi.begin(WIFI_SSID, WIFI_PASSWORD); þeklinde baðlantý saðlarýz.

#define FIREBASE_AUTH "41MqeGfErOCACpyb290ZMr0ekRDvdKjusCHqrxMn" þifremizi aldýðýmýz yer aþaðýda gösterilmiþtir.


Ardýndan baðlanma durumunu kod içerisinde kontrol ederek baðlanýlan IP adreslerini yazdýrýyoruz.
Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH); kodu ile firebase baðlantýsýný çalýþtýrýrýz.
Loop içerisinde  Serial.printf("Baðlanan Kiþi Sayýsý = %d\n", WiFi.softAPgetStationNum());
Firebase.setFloat("number", number);  kodlarýyla
 baðlanan kiþi sayýsýný arduino ekranýna ve firebase'e bu þekilde yazdýrmýþ oluruz.

5. SONUÇ
Projemizin sonucunda wifi baðlantýsý içindeki kiþileri ve toplam kiþi sayýsýný buluyoruz. 
  6.KAYNAKÇA

[1] http://umutonur.com/firebase-nedir-nasil-kullanilir-ve-ozellikleri-nelerdir/
[2] 
[3] https://maker.robotistan.com/esp8266-ile-iot-dersleri-1-esp8266-modulunu-guncelleme/

[4] https://www.artistanbul.io/blog/2016/09/29/app-inventor-nedir-nicin-onemlidir/

[5] https://www.technopat.net/2013/05/20/app-inventor-programlamaya-giris/

[6] http://www.kodlamadersi.com/mobil-uygulama-gelistirme-app-inventor.html

[7] https://firebase.google.com/

[8] https://medium.com/coinmonks/arduino-to-android-real-time-communication-for-iot-with-firebase-60df579f962
1


3


