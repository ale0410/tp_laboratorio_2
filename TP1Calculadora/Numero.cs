using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Calculadora
{
    class Numero
    {
        private double numero;

        /// <summary>
        /// La funcion que retorna el numero
        /// </summary>
        /// <returns></returns>
        public double getNumero()
        {
            return this.numero;
        }

        /// <summary>
        /// Inicializa el numero a 0
        /// </summary>
        public Numero()
        {
            numero = 0;
        }

        /// <summary>
        /// La funcion que parsea el numero
        /// </summary>
        /// <param name="numero"></param>
        public Numero(double numero)
        {
            numero = double.Parse(Console.ReadLine());
        }

        /// <summary>
        /// La funcion que muestra el numero
        /// </summary>
        /// <param name="numero"></param>
        public Numero(string numero)
        {
            numero = numero.ToString();
        }

        /// <summary>
        /// Valida el numero y devuelve 0 o el numero
        /// </summary>
        /// <param name="numeroString"></param>
        /// <returns></returns>
        private static double validarNumero(string numeroString)
        {
            bool parsear;
            double result;
            double num;

            parsear = double.TryParse(numeroString, out result);

            if (parsear == true)
            {
                num = result;
            }
            else
            {
                num = 0;
            }

            return num;
        }

        /// <summary>
        /// Muestra el numero
        /// </summary>
        /// <param name="numero"></param>
        private void setNumero(string numero)
        {
           this.numero = validarNumero(numero);
        }
    }
}
