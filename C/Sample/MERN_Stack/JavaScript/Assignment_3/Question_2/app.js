let num=prompt("Enter Number");
let final=num;
let count=1;
while(true){
    let digit=num%10;
    count+=1
    num-=digit;
    num/=10;
    if(num<9){
        break;
    }
    else{
        continue;
    }
}
if(final<9){
    console.log(`No of Digits: 1`);
}
else{
    console.log(`No of Digits: ${count}`);
}