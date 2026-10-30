let img=document.querySelector(".image");
let btn=document.querySelector("button");

btn.addEventListener("click",async()=>{
    try{
    await getimage();
    }
    catch(err){
        console.log(err);
    }
});

let url="https://dog.ceo/api/breeds/image/random";

async function getimage(){
    let res=await axios.get(url)
    img.setAttribute("src",res.data.message);
}
