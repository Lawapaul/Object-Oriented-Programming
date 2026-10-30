let arr=[1,2,3,4,5];
const newarr=arr.map((ele)=>(
    ele*ele
))
let sum=newarr.reduce((final,ele)=>
    final+ele
)
console.log(sum);
