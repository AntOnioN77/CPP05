# CPP05 - ex01

## Objetivo del ejercicio
Ampliar el ejercicio anterior incorporando `Form`:
- `name` constante.
- Estado de firma (`signed`) inicializado a `false`.
- Grado requerido para firmar y para ejecutar.
- Excepciones por grados fuera de rango.
- Método `beSigned(Bureaucrat const&)`.
- Integración con `Bureaucrat::signForm(Form&)`.

## Qué se valida en este ex
- Construcción válida e inválida de formularios.
- Firma rechazada cuando el burócrata no tiene rango suficiente.
- Firma aceptada cuando el rango es suficiente.
- Comprobación de estado de firma antes/después.
- Salida de `operator<<` con información completa del formulario.

## Archivos clave
- `Form.hpp` / `Form.cpp`: modelo del formulario y validaciones de firma.
- `Bureaucrat.hpp` / `Bureaucrat.cpp`: firma de formularios y reporte de resultado.
- `main.cpp`: pruebas de escenarios válidos e inválidos.
