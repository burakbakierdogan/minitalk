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
This program generates and sends a signal to a process. When run, it takes as its first argument a process ID and as its second argument a string. The program converts the string into an array and sends each element of the array as a signal. The signals can be of two different types: SIGUSR1 and SIGUSR2. These signals are user-defined signals and have no special meaning; however, they can be used for any desired operation by the program.

At the beginning, the program includes the library files it needs in the #include section. Then, it defines a function called ft_isspace. This function takes a character and checks if it is a white space character. If the character is a white space character, the function returns a value of 1. Otherwise, it returns a value of 0.

Then, it defines a function called ft_atoi. This function takes a string that represents an integer in a regular form and extracts and returns the integer value from the beginning of the string.

Next, it defines a function called ft_convert. This function takes an integer and converts it to binary. The binary value is written to a character array. This function also takes an index value that shows which index of the character array to use.
Then, it defines a Finally, the main function is defined. This function is the main entry point of the program and runs the rest of the program when run. The main function takes as input the number of arguments passed when run and an array of the arguments. If two arguments are passed when run (ac == 3), the program has received a process ID and a string. The ID is converted to an integer using the ft_atoi function and the string is allocated memory using the malloc function. Then, the main loop iterates through each character in the string and converts it to binary using the ft_convert function. The main loop also keeps track of the current index in the character array. After the main loop finishes, the ft_convert function is called one more time to convert the value 255 to binary and append it to the end of the character array. Finally, the ft_send_signal function is called to send the signals represented by the character array to the process with the given ID. The program ends by freeing the allocated memory and returning 0.

SERVER.C 
This program listens for signals and processes them. When run, it sets up two signal handlers, one for SIGUSR1 and one for SIGUSR2. These signal handlers are called ft_handler and are responsible for processing the signals received.

The program starts by including the necessary library files in the #include section. Then, it defines a function called ft_putnubr. This function takes an integer and writes it to standard output (stdout). It does this by recursively dividing the integer by 10 and writing the remainder to stdout.

Next, it defines the ft_handler function. This function takes an integer as input, which represents the signal number that was received. The function has two static variables, c and base. c is used to store the current value being processed and base is used as a base value to determine the place value of each signal received. If the signal received is SIGUSR1, the value of c is increased by base. If the signal received is SIGUSR2, the value of base is halved but the value of c remains unchanged. If the value of base becomes 0, it means that all signals for the current value have been received and it is time to process the value of c. If the value of c is 255, it means that the end of the message has been reached and c is reset to 0. If c is any other value, it is written to stdout and c is reset to 0.

Finally, the main function is defined. This function sets up the signal handlers for SIGUSR1 and SIGUSR2 using the signal function. It also initializes the pid variable to 0. In the main loop, if pid is 0, it gets the process ID using the getpid function and writes it to stdout. Then, the program waits for a signal to be received using the pause function. When a signal is received, the corresponding signal handler is called and the program continues processing. This loop continues indefinitely.

To use these programs, the server program must be run first. It will print out its process ID, which can then be used as the first argument when running the client program. The second argument of the client program is the string to be sent to the server. The client program will convert the string to binary and send it to the server as a series of signals. The server program will listen for these signals and convert them back into the original string, printing it out to stdout.

For example, to send the string "Hello, World!" from the client to the server, the following could be done:

Run the server program in a terminal window:
./server

Note the process ID printed by the server program.

Run the client program in a separate terminal window, using the process ID of the server as the first argument and the string to be sent as the second argument:

./client 12345 "Hello, World!"

The server program will receive the signals from the client and print out the original string:
Hello, World!

This is a simple example of how the client and server programs can be used to send and receive signals between processes. The specific implementation of the signal processing and conversion functions can be modified as needed for different applications.

**************TURKCE**********
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
