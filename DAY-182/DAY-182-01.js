var name ="ayush";
name = name.toUpperCase();
console.log(name);
var num1 = 10-7;
num1 = num1 + 2 * 3 /2;

function f1(a , b){
    return a + b;
}
f1(1,5);

function love(){
    prompt("what is your name ? : ");
    prompt("what is their name ? : ");
    var num = Math.random() * 100 ;
    var f = Math.floor(num) + 1;
    alert("Your Love Score Is " + f + "%");
    
}

love();

function love(){
    prompt("what is your name ? : ");
    prompt("what is their name ? : ");
    var num = Math.random() * 100 ;
    var f = Math.floor(num) + 1;
   
    if(f == 40){
         alert("Your Love Score Is " + f + "%" + " You Love each other like ");
    }
    else{
         alert("Your Love Score Is " + f + "%");
    }
    
}

love();