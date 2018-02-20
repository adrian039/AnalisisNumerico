format long

#Funcion auxiliar que calcula el factorial
function f = fact(n)
  if (n <= 1)
    f = 1;
  else
    f = n * fact(n - 1);
  endif
endfunction

#Funcion principal
function calcular(n,x)
  Real=exp(x)
  es=x*(10**(2-n));
  cont=0;
  aproxAct=0;
  aproxAnt=0;
  et=0;
  ea=es+1;
  while(ea>es)
    aproxAct+=(x**cont)/(fact(cont));
    et=((Real-aproxAct)/(Real))*100;
    ea=((aproxAct-aproxAnt)/(aproxAct))*100;
    aproxAnt=aproxAct;
    cont++;
  endwhile
  Aproximado=aproxAnt
  errVerd=((Real-Aproximado)/Real)*100
  errAprox=ea
endfunction

#Funcion de inicio del programa donde se capturan los datos
function beginning ()
  n= input ("--> Ingrese la cantidad de cifras significativas deseada: ");
  if(abs(mod(n,1))!=0)
    disp("--> Ingrese un numero entero !!!");
    beginning();
  elseif(n>15)
    disp("--> Ingrese un numero menor o igual a 15 !!!");
    beginning();
  else
    x= input ("--> Ingrese un valor para x: ");
    disp("\n");
    calcular(n,x);
  endif
endfunction
 
beginning()