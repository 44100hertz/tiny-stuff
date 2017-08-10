/* main(i){for(i=0;i++<100;)printf("%d\n\0  Fizz\n\0Buzz\n\0FizzBuzz\n"+6*!(i%3)+12*!(i%5),i);} */

main(i){for(;i<101;puts(i++%5?"":"buzz"))printf("%i\r%s",i,i%3?"":"fizz");}
