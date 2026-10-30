let arr=[1,2,3,4,5,6,2,3];
let num=2;
for(let i=0;i<arr.length;i++){
    if(arr[i]==num){
        arr.splice(i,1);
    }
}
for(let i=0;i<arr.length;i++){
    console.log(arr[i]);
}
