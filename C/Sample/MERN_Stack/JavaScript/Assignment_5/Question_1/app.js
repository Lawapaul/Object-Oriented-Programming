let arr=[4,6,8,11,15,21,26,9,45,73];
let num=prompt("Enter Number: ");
function main(){
    for(let i=0;i<arr.length;i++){
        if(arr[i]>num){
            console.log(arr[i]);
        }
        else{
            continue;
        }
    }
}
main();