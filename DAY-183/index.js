var randomNumber1 = Math.floor(Math.random() * 6) + 1 ;

var randDiceImg =  "dice" + randomNumber1 + ".png";
 
var randimgsrc = "images/" + randDiceImg;

var image1 = document.querySelectorAll("img")[0];

image1.setAttribute("src",randimgsrc);

var randomNumber2 =  Math.floor(Math.random() * 6) + 1 ;

var randomimg2 = "images/dice" + randomNumber2 +".png";

document.querySelectorAll("img")[1].setAttribute("src",randomimg2);

if(randomNumber1 > randomNumber2){
    document.querySelector("h1").innerHTML = "🏆 Play  1 Wins !";

}
else if(randomNumber1 < randomNumber2){
    document.querySelector("h1").innerHTML = "🏆 Play  2 Wins !";
}
else{
    document.querySelector("h1").innerHTML = "Draw";
}
