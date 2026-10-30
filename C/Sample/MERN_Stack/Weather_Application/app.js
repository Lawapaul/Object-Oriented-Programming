let btn=document.querySelector(".btn_search");
let inpu=document.querySelector('input');
btn.addEventListener('click',async()=>{
    await changetemp(inpu.value);
})
let h5=document.createElement("h3");
document.querySelector('.container').append(h5);
h5.style.display="none";
let url="https://api.openweathermap.org/data/2.5/weather?q="
let apikey="&units=metric&appid=4a38c099645773e0279a3dfcd6777ab7";
let img_weather=document.querySelector(".imag img");
async function changetemp(city){
    try{
    h5.innerText="City Not Found. Try Again";
    h5.style.display="none";
    let change= await axios.get(url+city+apikey)
    console.log(change);
    let select=document.querySelector('.weather')
    select.style.display="block";
    document.querySelector(".value").innerText=`${change.data.main.temp}`+"°c";
    document.querySelector(".city").innerText=inpu.value;
    document.querySelector(".humidity .text .percent").innerText=`${change.data.main.humidity}`+"%";
    document.querySelector(".wind .text .percent").innerText=`${change.data.wind.speed}`+"Km/h";
    if((change.data.weather[0].main)=="Clouds"){
        img_weather.setAttribute("src","images/clouds.png");
    }
    else if((change.data.weather[0].main)=="Haze"){
        img_weather.setAttribute("src","images/mist.png");
    }
    else if((change.data.weather[0].main)=="Rain"){
        img_weather.setAttribute("src","images/rain.png");
    }
    else if((change.data.weather[0].main)=="Drizzle"){
        img_weather.setAttribute("src","images/drizzle.png");
    }
    else if((change.data.weather[0].main)=="Clear"){
        img_weather.setAttribute("src","images/clear.png");
    }
    else if((change.data.weather[0].main)=="Snow"){
        img_weather.setAttribute("src","images/snow.png");
    }
    else{
        img_weather.setAttribute("src","images/clear.png");
    }
    }
    catch(err){
        document.querySelector(".weather").style.display="none";
        h5.style.display="block";
    }
    
}


inpu.addEventListener("keypress",async (event)=>{
    if((event.code)=="Enter"){
        await changetemp(inpu.value);
    }
})