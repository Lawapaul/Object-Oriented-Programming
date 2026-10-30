///Arrow Function that returns square of a number 'n'
const square=(n)=>{
    console.log(n*n);
}
///Arrow Function that prints hello world 5 times at intervals of 2s each;

let id=setInterval(()=>{
    console.log("Hello World")
},2000)
setTimeout(()=>{
    clearInterval(id)
},1000);