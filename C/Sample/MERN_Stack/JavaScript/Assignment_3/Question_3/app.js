let num=prompt("Enter Number");
let final=num;
let sum=0;
while(true){
    let digit=num%10;
    sum+=digit;
    num-=digit;
    num/=10;
    if(num<9){
        sum+=num;
        break;
    }
    else{
        continue;
    }
}

if(final<9){
    console.log(`Sum is ${final}`);
}
else{
    console.log(`Sum is ${sum}`)
}