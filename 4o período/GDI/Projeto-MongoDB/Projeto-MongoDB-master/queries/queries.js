use gdi;

//Seleciona os animais do cliente de id 2
db.pet.find({ client: { $exists: true, $all: [2] } }).pretty();

// Seleciona os animais que não receberam nenhuma dose de vacina
db.pet.find({ Vacinas: { $size: 0 } }).pretty();

// Listar nome e valor dos produtos que começam com nome "ração" (case-insensitive) ordenados por preço ascendente
db.product.aggregate([
  { $match: { Nome: /^ração/i } },
  { $sort: { Valor: 1 } },
  { $project: { _id: 0, Nome: 1, Valor: 1 } },
]).pretty();

//Seleciona as consultas cujo valor é superior ou igual a 100 reais
db.consultas.find({ valor: { $gte: 100 } }).pretty();

// Listar Nome, Total de consultas, valor total e médio das consultas dos veterinários da clínica
db.consultas.aggregate([
    {
      $lookup: {
        from: "vet",
        localField: "veterinario",
        foreignField: "_id",
        as: "veterinario_info",
      },
    },
    {
      $unwind: "$veterinario_info",
    },
    {
      $group: {
        _id: "$veterinario_info.Nome",
        total_consultas: { $count: {} },
        valor_total: { $sum: "$valor" },
        valor_medio: { $avg: "$valor" },
      },
    },
    {
      $project: {
        _id: 0,
        nome: "$_id",
        total_consultas: 1,
        valor_total: 1,
        valor_medio: 1,
      },
    },
  ]).pretty();

//Listar a quantidade de cachorros cadastrados no sistema
db.pet.aggregate([
  {
    $match: {
      Especie: "cachorro",
    },
  },
  {
    $group: {
      _id: null,
      count: {
        $count: {},
      },
    },
  },
  {
    $project: {
      _id: 0,
    },
  },
]).pretty();

// Listar CPF e nome do cliente de CPF "90129933007"
db.client.findOne({ CPF: "90129933007" }, { _id: 0, Nome: 1, CPF: 1 });

//Função que retorna uma mensagem indicando que o vet recebeu o pagamento da consulta.
db.consultas.aggregate([
  {
    $addFields: {
      message: {
        $function: {
          body: function (valor, data) {
            return `Opa!  Você recebeu o pagamento da consulta no valor de ${valor}, realizada no dia ${data}.`;
          },
          args: ["$valor", "$data"],
          lang: "js",
        },
      },
    },
  },
]).pretty();

//Procura todos os pets que são da raça salsisha
db.pet.createIndex({ Raca: "text" });
db.pet.find({
    $text: {
      $search: "salsisha",
    },
  }).pretty();

// Agendar uma consulta para a gatinha Juju no dia 21/08/2021 as 15:00 com a dra Beatriz
db.consultas.save({
  data: new Date("2021-08-21T15:00:00"),
  valor: 70,
  pet: 7,
  veterinario: 1,
  receituario: [],
});

// Atualizar o valor da Ivermectina de 10 para 15 reais - covid deixou mais caro
db.product.update({ Nome: /ivermectina/i }, { $set: { Valor: 15 } });

// Pegar as três consultas de maior valor
db.consultas.find().sort({ valor: -1 }).limit(3);

//ADD to SET
db.pet.update(
  { _id: 2 },
  {
    $addToSet: {
      Vacinas: { nome: "Antirrábica", dataAplicacao: new Date("2022-04-20") },
    },
  }
);

//map reduce pra transformar raca e especie em uma só
var map = function () {
  emit(this.Raca, this.Especie);
};
var reduce = function (Raca, Especie) {
  return Especie;
};

db.pet.mapReduce(map, reduce, { out: "results" });

// Aplicar um desconto de 20% nas rações e 10% nos outros produtos
db.product.aggregate([
    {
      $project: {
        _id: 0,
        Nome: 1,
        Valor: 1,
        ValorComDesconto: {
          $cond: [
            { $regexMatch: { input: "$Nome", regex: /ração/i } },
            { $multiply: ["$Valor", 0.8] },
            { $multiply: ["$Valor", 0.9] },
          ],
        },
      },
    },
  ]).pretty();

// $Where
db.consultas.find({
  $where: function () {
    return this.valor > 50;
  },
});

// Retornar consultas depois do dia 2021-08-17 às 16:00
db.consultas.find({
    $where: function () {
      return this.data > ISODate("2021-08-17T16:00:00");
    },
  }).pretty();

// Listar as vacinas aplicadas em 2020 para cada PET
db.pet.aggregate([
    {
      $project: {
        Nome: 1,
        vacinas: {
          $filter: {
            input: "$Vacinas",
            as: "vacina",
            cond: { $eq: [{ $year: "$$vacina.dataAplicacao" }, 2020] },
          },
        },
      },
    },
  ]).pretty();

//Renomear a coleção de veterinario
db.vet.renameCollection("veterinario");
