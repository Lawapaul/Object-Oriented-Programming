let max=prompt("Enter Max limit: ");
let ran=Math.floor(Math.random()*max)+1;
let count=0;
console.log(ran)
while(true){
    let guess=prompt("Guess: ");
    if(guess==ran){
        count+=1;
        console.log(`You Won in ${count} chances!!!!`);
        break;
    }
    else{
        count+=1;
        continue;
    }

}