
const doubleAndReturnArgs=(arr,...args)=>[
    ...arr,
    ...args.map((i)=>i*2)

];
doubleAndReturnArgs()