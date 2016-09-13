using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Calculadora
{
    class Calculadora
    {
        /// <summary>
        /// La funcion que opera y devuelve el resultado
        /// </summary>
        /// <param name="numero1"></param>
        /// <param name="numero2"></param>
        /// <param name="operador"></param>
        /// <returns></returns>
        public static double operar(Numero numero1, Numero numero2, string operador)
        {
            double result=0;
            double num1;
            double num2;
            operador = Calculadora.validarOperador(operador);
            num1 = numero1.getNumero();
            num2 = numero2.getNumero();

            switch (operador)
            {
                case "+":
                    result = num1 + num2;
                    break;
                case "-":
                    result = num1 - num2;
                    break;
                case "*":
                    result = num1 * num2;
                    break;
                case "/":
                    if (num2 == 0)
                    {
                        result = 0;
                    }
                    else
                    {
                        result = num1 / num2;
                    }
                    break;
            }

            return result;

        }

        /// <summary>
        /// La funcion que valida el operador
        /// </summary>
        /// <param name="operador"></param>
        /// <returns></returns>
        public static string validarOperador(string operador)
        {
            if(operador == "+" || operador == "-" || operador == "*" || operador == "/")
            {
                return operador;
            }
            else
            {
               
               return "+";
            }
        }
    }
}
