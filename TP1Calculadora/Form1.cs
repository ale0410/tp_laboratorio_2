using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Calculadora
{
    public partial class Form1 : Form
    {
        /// <summary>
        /// Inicializa el componente
        /// </summary>
        public Form1()
        {
            InitializeComponent();
        }

        /// <summary>
        /// Retorna un void
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void Form1_Load(object sender, EventArgs e)
        {

        }

        /// <summary>
        /// Copia los datos de los numeros y devuelve el resultado
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void btnOperar_Click(object sender, EventArgs e)
        {
            Numero numero1 = new Numero(this.txtNumero1.Text);
            Numero numero2 = new Numero(this.txtNumero2.Text);


            this.lblResultado.Text = Calculadora.operar(numero1, numero2,this.cmbOperacion.Text).ToString();
        }

        /// <summary>
        /// Muestra el resultado
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void lblResultado_Click(object sender, EventArgs e)
        {
            //int resultado = 0;

            //this.lblResultado.Text = resultado.ToString();
        }

        /// <summary>
        /// Devuelve el primer numero
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void txtNumero1_TextChanged(object sender, EventArgs e)
        {

        }

        /// <summary>
        /// Limpia la calculadora
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void btnLimpiar_Click(object sender, EventArgs e)
        {
            this.txtNumero1.Text = "";
            this.txtNumero2.Text = "";
            this.cmbOperacion.Text ="";
            this.lblResultado.Text ="";
        }
    
    }
}
