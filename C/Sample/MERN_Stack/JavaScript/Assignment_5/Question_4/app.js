let str="hello harshit singh shekhawat";
function vowel(){
    let count=0;
    for(let i=0;i<str.length;i++){
        if(str[i]=="a" || str[i]=="e" || str[i]=="i" || str[i]=="o" || str[i]=="u"){
            count++;
        }
        else{
            continue;
        }
    }
    console.log(count);
}
vowel();