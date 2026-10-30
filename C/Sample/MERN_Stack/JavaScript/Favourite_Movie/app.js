let fav="avatar";
let guess=prompt("Enter Movie: ");

while((guess!=fav) && (guess!="quit")){
    let m=prompt("Wrong Guess, Enter Again: ");
    if(m==fav){
        console.log("Guessed Correct!!!");
        break;
    }
    else if(m=="quit"){
        console.log("Thankyou for playing!!");
        break;
    }
    else{
        continue;
    }
}