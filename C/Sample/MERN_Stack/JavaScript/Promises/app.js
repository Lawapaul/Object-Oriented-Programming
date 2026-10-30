let h1=document.querySelector("h1");
function ColorChange(data,delay){
    return new Promise((resolve,revoke)=>{
        setTimeout(()=>{
            h1.style.color=data;
            console.log(`Color Changed to ${data}`)
            resolve("Color Changed");
        },delay);
    });
}
async function demo(){
    try{
    await ColorChange("orange",1000);
    await ColorChange("Yellow",1000);
    await ColorChange("green",1000);
    await ColorChange("blue",1000);
}
catch(err){
    console.log(err);
}
}
// ColorChange("red",1000).then(()=>{
//     console.log("Color Changed to Red")
//     return ColorChange("orange",1000);
// })
// .then(()=>{
//     console.log("Color Changed to Orange")
//     return ColorChange("Yellow",1000);
// })
// .then(()=>{
//     console.log("Color Changed to Yellow")
//     return ColorChange("blue",1000);
// })
// .then(()=>{
//     console.log("Color Changed to Blue");
// })

demo();