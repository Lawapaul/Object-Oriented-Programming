///If every element in Array is mulitple of 10 or not

let arr=[5,10,15,20,25,30,35,40];
let ans=arr.every((el)=>{
    return el%10==0;
});

///Functoin to find min of array

let arr1=[2,4,5,1,3,5,-8];
function check(){
    let final=arr1.reduce((min,i)=>{
        if(min<i){
            return min
        }
        else{
            return i;
        }
    });
    return final;
}
console.log(check());

