let url="http://universities.hipolabs.com/search?name="
let inpu=document.querySelector('input');
let btn=document.querySelector('button');
let p=document.querySelector('p');
let country=inpu.value;

btn.addEventListener('click',async()=>{
    await getdata();
})
let str=""
async function getdata(){
    let res=await axios.get(url+inpu.value);
    let ul=document.createElement('ul');
    document.querySelector('body').append(ul)
    let li=document
    for(let i=0;i<res.data.length;i++){
        let li=document.createElement('li');
        document.querySelector('ul').append(li);
        li.innerText=res.data[i].name
    }
    p.innerText=str;
}
