using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Blazor_Server.Models
{
    public class ContaBancaria
    {
        public string? Banco { get; set; }

        public string? Agencia { get; set; }
        
        public string? Conta { get; set; }
    }
}
