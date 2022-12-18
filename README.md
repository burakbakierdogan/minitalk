# minitalk
The purpose of this project is to code a small data exchange program using UNIX signals.
With the make command, server and client executables files will be ready to be executed. 

Open 2 seperate terminals. 
In one of them, run ./server and copy the printed pid number in the terminal.
In the other one, run ./client and enter pid number as an argument along with the message you would like to send to the server.
The server will print the message in its terminal. 
The aim of this project is sending Unix signals between processes. 
I convert signals to the strings.

CLIENT.C
Bu program, bir sinyal oluşturup bir işleme gönderir. Program çalıştırıldığında, ilk argüman olarak bir işlem (process) ID'si ve ikinci argüman olarak bir metin alır. Program, metni bir diziye dönüştürür ve dizinin her elemanını bir sinyal olarak gönderir. Sinyaller, iki farklı türden olabilir: SIGUSR1 ve SIGUSR2. Bu sinyaller, kullanıcı tarafından tanımlanmış sinyallerdir ve özel bir anlamı yoktur; ancak, program tarafından istenilen işlemler için kullanılabilirler.

Program, başlangıçta #include bölümünde ihtiyaç duyduğu kütüphane dosyalarını dahil eder. Daha sonra, ft_isspace adında bir fonksiyon tanımlanır. Bu fonksiyon, bir karakter alır ve karakterin bir boşluk karakteri olup olmadığını kontrol eder. Eğer karakter bir boşluk karakteriyse, fonksiyon 1 değerini döndürür. Aksi halde, 0 değerini döndürür.

Sonra, ft_atoi adlı bir fonksiyon tanımlanır. Bu fonksiyon, bir düzenli tamsayı değeri döndürecek şekilde bir karakter dizisi (string) alır. Fonksiyon, dizinin ilk elemanından başlayarak sayı değerini çıkartır ve döndürür.

Daha sonra, ft_convert adlı bir fonksiyon tanımlanır. Bu fonksiyon, bir tamsayı alır ve bu tamsayıyı ikilik sistemine çevirir. İkilik sistemdeki değer, bir karakter dizisine yazılır. Bu fonksiyon ayrıca, karakter dizisinin hangi indeksinin kullanılacağını gösteren bir indeks değeri alır.

Sonra, ft_send_signal adlı bir fonksiyon tanımlanır. Bu fonksiyon, bir karakter dizisi, bir indeks değeri ve bir işlem ID'si alır. Fonksiyon, dizinin her elemanını sırayla işleme gönderir. Eğer eleman '1' ise, SIGUSR1 sinyali gönderilir.
Eğer eleman '0' ise, SIGUSR2 sinyali gönderilir. Bu sinyaller, kill fonksiyonu kullanılarak gönderilir.

Son olarak, main fonksiyonu tanımlanır. Bu fonksiyon, programın ana girdi noktasıdır ve çalıştırıldığında programın geri kalanını çalıştırır. main fonksiyonu, çalıştırıldığında kaç tane argüman alındığını gösteren bir sayı ve argümanların dizisi alır. Eğer çalıştırıldığında iki argüman alındıysa (ac == 3), program bir işlem ID'si ve bir metin almıştır. Bu ID, ft_atoi fonksiyonu kullanılarak tamsayı değerine dönüştürülür. Daha sonra, bir karakter dizisi oluşturulur ve metin, ft_convert fonksiyonu kullanılarak bu diziye dönüştürülür. Daha sonra, ft_send_signal fonksiyonu kullanılarak bu dizi, işlem ID'sine gönderilir. Program sonlandırıldıktan sonra, oluşturulan dizi hafızadan silinir ve program sonlandırılır.

SERVER.C
Bu program, bir işlem (process) ID'si ve bu ID'ye ait olan sinyalleri alır. Program, sinyalleri alır ve bu sinyallerin bir diziye nasıl dönüştürüleceğini gösterir. Sinyaller, iki farklı türden olabilir: SIGUSR1 ve SIGUSR2. Bu sinyaller, kullanıcı tarafından tanımlanmış sinyallerdir ve özel bir anlamı yoktur; ancak, program tarafından istenilen işlemler için kullanılabilirler.
Program, başlangıçta #include bölümünde ihtiyaç duyduğu kütüphane dosyalarını dahil eder. Daha sonra, ft_putnubr adında bir fonksiyon tanımlanır. Bu fonksiyon, bir tamsayı değer alır ve bu değeri ekrana yazdırır. Fonksiyon, tamsayıyı rakamlarına ayırarak yazdırır. Örneğin, değer 123 ise, fonksiyon 1, 2 ve 3 rakamlarını ekrana yazdırır.

Sonra, ft_handler adlı bir fonksiyon tanımlanır. Bu fonksiyon, bir sinyal numarası alır ve bu sinyal numarasına göre işlem yapar. Eğer sinyal numarası SIGUSR1 ise, fonksiyon bir sayaç değişkenini arttırır ve bir taban değişkenini yarıya düşürür. Eğer sinyal numarası SIGUSR2 ise, fonksiyon sadece taban değişkenini yarıya düşürür. Eğer taban değişkeni sıfıra eşitse, fonksiyon sayaç değişkenini ekrana yazdırır ve sayaç ve taban değişkenlerini sıfırlar.

Son olarak, main fonksiyonu tanımlanır. Bu fonksiyon, programın ana girdi noktasıdır ve çalıştırıldığında programın geri kalanını çalıştırır. main fonksiyonu, çalıştırıldığında hiçbir argüman almaz. Fonksiyon, signal fonksiyonu kullanılarak SIGUSR1 ve SIGUSR2 sinyallerine ft_handler fonksiyonunu atar. Daha sonra, bir döngü oluşturulur ve bu döngü sürekli olarak çalışır. Eğer işlem ID'si (pid) sıfıra eşitse, ID'nin değeri getpid fonksiyonu kullanılarak alınır ve ID, ft_putnubr fonksiyonu kullanılarak ekrana yazdırılır. Daha sonra, program pause fonksiyonu ile bekletilir ve bekleme sırasında bir sinyal alınırsa, ft_handler fonksiyonu çağrılır ve işleme devam edilir. Bu şekilde, program sürekli olarak sinyalleri alır ve bu sinyalleri işler.
