#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
// Cada prueba está alineada con los requisitos del enunciado de ex01.
// TEST 1: formulario válido (debe construirse sin excepción).
try
{
Form M35A("M35A", 35, 40);
std::cout << "[TEST 1 SUPERADO] Formulario M35A creado con éxito." << std::endl;
}
catch(const std::exception& e)
{
std::cout << "[TEST 1 FALLIDO] Esperado: Creación del formulario exitosa. Obtenido: " << e.what() << std::endl;
}

// TEST 2: grados fuera de rango por arriba (<1) durante la construcción.
try
{
Form M35A("M35A", -1, 40);
std::cout << "[TEST 2 FALLIDO] Esperado: GradeTooHighException. Obtenido: Formulario creado con éxito." << std::endl;
}
catch(const std::exception& e)
{
std::cout << "[TEST 2 SUPERADO] Excepción esperada:GradeTooHighException. Capturada:" << e.what() << std::endl;
}

// TEST 3: signForm falla por falta de rango suficiente.
// Requisito: Form::beSigned debe rechazar burócratas con rango insuficiente.
{
Bureaucrat Oscar("Oscar", 2);
Form Orden_Suprema("Orden_Suprema", 1, 40);

if (Oscar.signForm(Orden_Suprema) == true)
std::cout << "[TEST 3A FALLIDO] Esperado: GradeTooLowException. Obtenido: Formulario firmado con éxito." << std::endl;
else
std::cout << "[TEST 3A SUPERADO] Formulario no firmado." << std::endl;

if (Orden_Suprema.getSignature() == false)
std::cout << "[TEST 3B SUPERADO] Formulario no firmado." << std::endl;
else
std::cout << "[TEST 3B FALLIDO] Esperado: Formulario no firmado. Obtenido: Formulario firmado." << std::endl;
}

// TEST 4: signForm exitoso y comprobación del estado de firma.
// Requisito: si el grado es suficiente, el formulario pasa a firmado.
{
Bureaucrat PedroP("PedroP", 1);
Form Orden_Suprema("Orden_Suprema", 1, 40);
if (PedroP.signForm(Orden_Suprema) == true)
std::cout << "[TEST 4A SUPERADO] Formulario firmado con éxito por PedroP." << std::endl;
else
std::cout << "[TEST 4A FALLIDO] Esperado: Formulario firmado con éxito. Obtenido: Formulario no firmado." << std::endl;

if (Orden_Suprema.getSignature() == true)
std::cout << "[TEST 4B SUPERADO] Formulario firmado correctamente." << std::endl;
else
std::cout << "[TEST 4B FALLIDO] Esperado: Formulario firmado. Obtenido: Formulario no firmado." << std::endl;
}

// TEST 5: constructor con gradeToExecute fuera de rango (>150).
try
{
Form F("F", 50, 151);
std::cout << "[TEST 5 FALLIDO] Esperado: GradeTooLowException. Obtenido: Formulario creado." << std::endl;
}
catch(const std::exception& e)
{
std::cout << "[TEST 5 SUPERADO] Excepción esperada: GradeTooLowException. Capturada: " << e.what() << std::endl;
}

// TEST 6: validación visual de operator<< antes y después de firmar.
// Requisito: operator<< debe mostrar todos los datos relevantes del formulario.
{
Form Formulario_Test_out("Formulario_Test_out", 42, 10);
std::cout << "[TEST 6A] Output operator<< (No signed):" << std::endl;
std::cout << Formulario_Test_out;

std::cout << "[TEST 6B] Output operator<< (Signed):" << std::endl;
Bureaucrat Marvin("Marvin", 42);
Marvin.signForm(Formulario_Test_out);
std::cout << Formulario_Test_out;
}

return 0;
}
