# CPP05 - ex02

## Objetivo del ejercicio
Convertir `Form` en clase abstracta `AForm` y crear formularios concretos:
- `ShrubberyCreationForm` (sign 145 / exec 137).
- `RobotomyRequestForm` (sign 72 / exec 45).
- `PresidentialPardonForm` (sign 25 / exec 5).

Además:
- Añadir `execute(Bureaucrat const&) const` en la jerarquía.
- Verificar que el formulario esté firmado antes de ejecutar.
- Verificar que el ejecutor tenga rango suficiente.
- Añadir `Bureaucrat::executeForm(AForm const&)`.

## Qué se valida en este ex
- Flujo completo de firma + ejecución de cada tipo de formulario.
- Errores por grados insuficientes al firmar o ejecutar.
- Comportamiento específico de cada acción:
  - creación de archivo `_shrubbery`,
  - robotomía con éxito/fallo aleatorio,
  - mensaje de indulto presidencial.

## Archivos clave
- `AForm.hpp` / `AForm.cpp`: base abstracta y validaciones comunes.
- `*Form.hpp` / `*Form.cpp`: acciones concretas por tipo de formulario.
- `Bureaucrat.hpp` / `Bureaucrat.cpp`: integración de ejecución.
- `main.cpp`: pruebas funcionales del flujo completo.
