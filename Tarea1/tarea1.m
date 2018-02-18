format long

function f = fact(n)
  if (n <= 1)
    f = 1;
  else
    f = n * fact(n - 1);
  endif
endfunction

function resp = calcular(n,x)
  resp=1+x;
  for i=2:n
    resp+=(x**i)/fact(i);
  endfor
endfunction

function beginning ()
  n= input ("Ingrese la cantidad de cifras significativas deseada: ");
  if(n>15)
    disp("Ingrese un numero menor o igual a 15 !!!")
    beginning()
  else
    x= input ("Ingrese un valor para x: ");
    real=exp(x)
    estimado=calcular(n,x)
    errVerd=((real-estimado)/real)*100
    errAprox=((x^(n-1))/(fact(n-1)*calcular(n-1,x)))*100
  endif
 
endfunction
 
beginning()