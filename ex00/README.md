# CPP05 - ex00

## Objetivo del ejercicio
Implementar la clase `Bureaucrat` con:
- `name` constante.
- `grade` en el rango `[1, 150]` (1 = mayor rango).
- Excepciones `GradeTooHighException` y `GradeTooLowException` al construir o modificar un grado fuera de rango.
- Sobrecarga de `operator<<` con el formato:
  - `<name>, bureaucrat grade <grade>.`

## Qué se valida en este ex
- Construcción válida con límites correctos.
- Construcción inválida con grado `0` y `151`.
- `upGrade()` y `downGrade()` respetando el rango permitido.
- Captura de excepciones vía `std::exception`.

## Archivos clave
- `Bureaucrat.hpp` / `Bureaucrat.cpp`: definición e implementación de la clase.
- `main.cpp`: pruebas manuales de comportamiento nominal y de error.
- `Makefile`: compilación con flags del módulo.
