let btn=document.querySelector('button');
let p=document.querySelector(".inner")
btn.addEventListener("click",()=>{
    getfact();
})
let url="https://catfact.ninja/fact";
async function getfact(){
    let res=await axios.get(url);
    p.innerText=res.data.fact;
}