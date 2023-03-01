<!DOCTYPE html>
<html>
<body>

<?php
    $surname = "Шевченко"; 
    $number = 1269794645; 
    $pi = 3.14159265; 
    $hello = "Hi all";

    $name = "Тарас"; 
    echo "Ваше ім'я ", $name; 

    $capital = "Paris"; 
    echo "The capital of France is $capital";

    $text = "news"; 
    echo "Where's the $textpaper"; 
    echo "Where's the {$text}paper";


    // Константи в PHP
    define("pi", 3.14); 
    echo "Число пі дорівнює ", pi;


    // Типи даних PHP
    $bool = TRUE;    // Значення Boolean
    $int = 100;    // Значення Integer
    $string = "Змінна містить текст";    // Значення String
    $string2 = "5425";    // Значення String, так як число взято в лапки !
    $float = 44.122;    // Значення Float


    // Для запобігання появи помилок рекомендується не змішувати різні типи даних. Якщо ви хочете явно змінити тип даних змінної, то для цього потрібно зліва від імені змінної в круглих дужках вказати потрібний тип

    $str = "50000";    // Значення String
    $new_str = (integer) $str;    // Тепер значення стало Integer



    // Математичні оператори та математичні функції PHP
    echo "2 + 2 = ", 2 + 2, "<br>"; 
    echo "5 - 2 = ", 5 - 2, "<br>"; 
    echo "10 * 10 = ", 10 * 10, "<br>"; 
    echo "100 / 2 = ", 100 / 2, "<br>"; 
    echo "10 % 2 = ", 10 % 2, "<br>";

    $a = $b = $c = $d = 2; 

    echo $a++, "<br>";
    echo ++$b, "<br>";
    echo $c--, "<br>";
    echo --$d, "<br>";

    $d = "Hello";
    $f = $d." world";   // Тепер $f = "Hello world"
    echo $f; 
    echo ""; 
    $f .= " ! ! !";   // Тепер $f = "Hello world ! ! !"
    echo $f; 

    // Умовний оператор IF в PHP
    $speed = 80;
    if ($speed > 60) 
    {
        echo "Перевищення швидкості !";
    }
    elseif ($speed == 50)
    {
        echo "Нормальна швидкість";
    }
    else 
    {
        echo "Ваша швидкість $speed км/год";
    }


    // Цикли в PHP

    for ($i = 0; $i < 10; $i++) 
    {
        echo "Вивід стрічки. 10 раз <br>"; 
    } 
    
    $counter = 0; 
    while ($counter < 5) 
    {
        echo "Ця стрічка виведеться 5 раз"; 
        $counter++;
    }

    $counter = 6; 
    do
    {
        echo "Ця стрічка виведеться 1 раз"; 
        $counter++;
    }
    while ($counter < 5);


    $array = array ("Apple", "Limon", "Chery", "Oranges"); 
    foreach ($array as $value)
    {
        echo "Ви обрали фрукт - $value"; 
    }

    // Масиви в PHP
    // $arr[0] = "php";
    // $arr[1] = "html";
    // $arr[2] = "css";

    // В якості індексу елементів масиву ми можемо використовувати не тільки числа:
    // $arr["Kiev"] = 3000000; 
    // $arr["Paris"] = 5000000; 
    // $arr["LA"] = 15000000;

    // Також існує скорочений запис для індексування
    // $arr[] = 3000000; 
    // $arr[] = 5000000; 
    // $arr[] = 15000000;

    // $arr = array("php", "html", "css");
    // У цьому випадку перший елемент отримає індекс 0. Якщо потрібно присвоїти якийсь інший номер, то можна скористатися конструкцією =>
    // $arr = array(1 => "php", "html", "css");
    // $arr = array("first" => "php", "second" => "html", "third" => "css");

    // $arr = ["php", "laravel", "yii", "zend", "cakephp"];

    // виведення всіх елементів масиву на екран

    // print_r($arr);

    foreach($arr as $value)
    { 
        echo $value, "<br>";
    } 

    foreach($arr as $key => $value)
    { 
        // $key - індекс елементу масива, $value - значення елементу масива
        echo "[{$key}] => {$value} <br/>";
    }

    // $arr[0] = "PHP"; 
    // $arr[1] = "HTML"; 
    // $arr[2] = "CSS";
    
    // sort($arr); 
    // print_r($arr);


    // $arr[0] = "PHP"; 
    // $arr[1] = "CSS"; 
    // $arr[2] = "HTML";

    // rsort($arr); 
    // print_r($arr);

    // $arr[0] = "PHP"; 
    // $arr[1] = "HTML"; 
    // $arr[2] = "CSS";

    // krsort($arr); 
    // print_r($arr); 

    // $arr[0] = "PHP"; 
    // $arr[1] = "HTML"; 
    // $arr[2] = "CSS";

    // $string = implode(", ", $arr);
    // echo $string; 

    // $string = "PHP, HTML, CSS";
    // $arr = explode(", ", $string);
    // print_r($arr); 


    // $arr["one"] = "PHP"; 
    // $arr["two"] = "HTML"; 
    // $arr["three"] = "CSS";

    // extract($arr); 

    // echo "\$one = $one <br>";
    // echo "\$two = $two <br>";
    // echo "\$three = $three <br>"; 


    // function square($num)
    // {
    //     $square = $num * $num;
    //     echo $square;
    // }	
    // square(7);


    function myfunc($x,$y)
    {
        $res = cos($x) + sin($y) + 2;
        return $res;
     }
     
     $x = 5;
     $y = 7;
     
     $z = myfunc($x,$y);
     
     echo $z;    
?>


<form action="app/check.php" method="post">
    <p>Name: <input name="name" type="text"></p>
    <p>Last name: <input name="surname" type="text"></p>
    <p>E-mail: <input name="email" type="text"></p>
    <p>Message: <br /><textarea name="message" cols="30" rows="5"></textarea></p>

    <p><input type='submit' value='Send'></p>
</form>

<?php
    if($_SERVER['REQUEST_METHOD'] == 'POST')
    {
        $name = $_POST['name'];
        $surname = $_POST['surname'];
        $email = $_POST['email'];
        $message = $_POST['message']; 

        echo $name."<br />".$surname."<br />".$email."<br />".$message."<br />"; 
    }


    function clean($value = "") {

        // trim для видалення пробілів з початку і кінця рядка
        $value = trim($value);

        // stripslashes потрібна для видалення екранованих символів ( "Ваc звуть O\'reilly?" => "Вас звати O'reilly?")
        $value = stripslashes($value); 

        //  strip_tags потрібна для видалення HTML і PHP тегів
        $value = strip_tags($value);

        // htmlspecialchars перетворює спеціальні символи в HTML-сутності ( '&' перетворюється в '& amp;' і т.д.)
        $value = htmlspecialchars($value);
        
        return $value;
    }

    // class MyClass 
    // { 
    //     // Методи класу 
    // } 

    // $obj = new MyClass; 
    // var_dump($obj); 


    // class MyClass 
    // { 
    //     public $prop1 = "I'm a class property!"; 
    // } 

    // $obj = new MyClass; 
    // echo $obj->prop1; // Output the property 


    // class MyClass 
    // { 
    //     private $prop1 = "I'm a class property!"; 
    //     public function setProperty ($newval) { 
    //         $this-> prop1 = $newval; 
    //     } 

    //     public function getProperty () { 
    //         return $this-> prop1. ""; 
    //     } 
    // } 

    // $obj = new MyClass; 
    // echo $obj-> getProperty (); // Get the property value 
    // $obj-> setProperty ("I'm a new property value!"); //Set a new one 
    // echo $obj-> getProperty(); // Read it out again to show the change 

    // class MyClass 
    // { 
    //    public $prop1 = "I'm a class property!"; 
    //    public function __construct () 
    //    { 
    //        echo 'The class "', __CLASS__, '" was initiated! '; 
    //    } 

    //    public function __destruct () 
    //    { 
    //        echo 'The class "', __CLASS__, '" was destroyed. '; 
    //    } 

    //    public function setProperty ($newval) 
    //    { 
    //        $this->prop1 = $newval; 
    //    } 

    //    public function getProperty () 
    //    { 
    //        return $this-> prop1. ""; 
    //    } 
    // } 

    class MyClass 
    { 
        public $prop1 = "I'm a class property!"; 

        public function __construct () 
        { 
            echo 'The class "', __CLASS__, '" was initiated! '; 
        } 

        public function __destruct () 
        { 
            echo 'The class "', __CLASS__, '" was destroyed. '; 
        } 

        public function __toString () 
        { 
            echo "Using the toString method:"; 
            return $this-> getProperty (); 
        } 

        public function setProperty ($newval) 
        { 
            $this-> prop1 = $newval; 
        } 

        public function getProperty () 
        { 
            return $this-> prop1. ""; 
        } 
    } 

    class MyOtherClass extends MyClass 
    { 
        public function newMethod () 
        { 
            echo "From a new method in". __CLASS__. ". "; 
        } 
    } 
?>  

</body>
</html>



