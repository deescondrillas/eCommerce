# eCommerce
Proyecto Final – Pensamiento Computacional Orientado a Objetos

Este proyecto consiste en la creación de un sistema de pagos que garantice la seguridad del cliente. Para ello, se va a diseñar el backend de una aplicación intermediaria que mantenga en privado los datos de pago del cliente. A la hora de pagar, el sistema generará una cuenta digital temporal para hacer el pago en línea. Además, podrá recibir opcionalmente una cantidad máxima de dinero a retirar para evitar que se hagan cargos adicionales a la cuenta bancaria del cliente.

El problema específico que se busca atender con esta solución es hacer los pagos digitales más seguros para motivar a los compradores análogos a entrar en el negocio digital y comprar los productos de diversos negocios.

Descripción:
El programa en su totalidad fue diseñado con el lenguaje de programación C++. Específicamente, se crearon distintas clases para abstraer la situación, tales como cliente, tarjeta y token. Cliente y token son clases compuestas por tarjeta, pues su definición incluye atributos que pertenecen a esta clase. Por otro lado, cliente y token son clases agregadas, pues una puede tener acceso a la otra mas no tienen elementos pertenecientes a la otra clase.

Valores de Entrada:
  Al registrarse:
  - Nombre de usuario
  - Contraseña
  - Número de tarjeta
  - Fecha de vencimiento
  - CVV
  - Cantidad de dinero
  Al realizar un pago:
  - Nombre de usuario
  - Contraseña
  - Monto máximo a cobrar (opcional)

Valores de Retorno:
  Cuando el usuario quiere revisar su estado de cuenta:
  - Nombre de usuario
  - Cantidad de dinero
  - Historial de compras
  Cuando se quiere realizar un pago
  - Número de cuenta temporal
  - Fecha de vencimiento temporal
  - Token aleatorio temporal
  - Mensaje de error (en caso de que no se cumplan las condiciones)

  \* en caso de que se haga un pago durante el lapso de tiempo que dura el token, entonces el sistema retirará la cantidad de dinero de la cuenta del cliente y la transferirá a la cuenta temporal para que se haga el cargo. Si se intentan realizar varios cobros, la cantidad de dinero a retirar supera el límite máximo establecido o la cuenta del cliente no tiene suficiente dinero, entonces se regresará un mensaje de error.

Limitaciones:
...

Diagrama de clases:
...

Casos de prueba:
(Simulación en consola...)
