# CPP05 - ex03

## Objetivo del ejercicio
Implementar `Intern` como fábrica de formularios (`makeForm`):
- Entrada: nombre de formulario + target.
- Salida: `AForm*` del tipo solicitado, con target inicializado.
- Si el nombre no existe, informar error de forma explícita.

## Qué se valida en este ex
- Creación correcta de:
  - `robotomy request`,
  - `shrubbery creation`,
  - `presidential pardon`.
- Gestión de un nombre de formulario inválido.
- Uso de memoria dinámicamente reservada y liberada tras crear formularios.

## Archivos clave
- `Intern.hpp` / `Intern.cpp`: lógica de selección y creación de formularios.
- Resto de jerarquía `AForm` y derivados: reutilizada del ex02.
- `main.cpp`: casos de prueba para cada nombre soportado y caso inválido.
