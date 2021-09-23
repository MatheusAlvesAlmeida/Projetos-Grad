db.consultas.insertMany([
  {
    _id: 0,
    data: new Date("2021-08-18T15:00:00"),
    valor: 150,
    pet: 2,
    veterinario: 2,
    receituario: [
      {
        quantidade: 2,
        produto: 2,
        frequencia: "3 vezes ao dia",
      },
    ],
  },
  {
    _id: 1,
    data: new Date("2021-08-18T16:00:00"),
    valor: 50,
    pet: 4,
    veterinario: 1,
    receituario: [],
  },
  {
    _id: 2,
    data: new Date("2021-08-18T14:00:00"),
    valor: 100,
    pet: 6,
    veterinario: 0,
    receituario: [
      {
        quantidade: 1,
        produto: 7,
        frequencia: "1 dose diária de 1 unidade pela manhã",
      },
    ],
  },
  {
    _id: 3,
    data: new Date("2021-08-17T14:00:00"),
    valor: 75,
    pet: 6,
    veterinario: 0,
    receituario: [
      {
        quantidade: 5,
        produto: 6,
        frequencia: "Aplicar no ferimento diariamente",
      },
    ],
  },
  {
    _id: 4,
    data: new Date("2021-04-18T15:00:00"),
    valor: 320,
    pet: 7,
    veterinario: 0,
    receituario: [
      {
        quantidade: 4,
        produto: 6,
        frequencia: "1 dose a cada 15 dias por 1 mês",
      },
    ],
  },
]);
