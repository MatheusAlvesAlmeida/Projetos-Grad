db.client.insertMany([
    {
        _id: 1,
        CPF: '46001364036',
        Nome: 'Matheus',
        Endereco: {
            Descricao: 'Rua da pedreira',
            Cep: '5680000',
            Cidade: 'Tabira'
        },
        Telefones: ['8138943935', '81996262906'],
    },
    {
        _id: 2,
        CPF: '54833869063',
        Nome: 'João',
        Endereco: {
            Descricao: 'Rua do perfume fresco',
            Cep: '5680000',
            Cidade: 'Ingazeira'
        },
        Telefones: ['8129777653', '81998209667'],
    },
    {
        _id: 3,
        CPF: '90129933007',
        Nome: 'Bruno',
        Endereco: {
            Descricao: 'Avenida Brasil',
            Cep: '5744522',
            Cidade: 'Jaboatão'
        },
        Telefones: ['8128516560', '81994097822'],
    },
    {
        _id: 4,
        CPF: '68079831076',
        Nome: 'Toni',
        Endereco: {
            Descricao: 'Travessa Antonio Maciel',
            Cep: '12321321',
            Cidade: 'Recife'
        },
        Telefones: ['8137789422', '81981702375'],
    },
    {
        _id: 5,
        CPF: '77321500071',
        Nome: 'Gabriel',
        Endereco: {
            Descricao: 'Rua da lagoinha',
            Cep: '5680000',
            Cidade: 'Afogados da Ingazeira'
        },
        Telefones: ['81999089790'],
    },
    {
        _id: 6,
        CPF: '70081944470',
        Nome: 'Carla Gabriela Aurora Aragão',
        Endereco: {
            Descricao: 'Rua Deputado Ângelo Jordão',
            Cep: '50690170',
            Cidade: 'Recife'
        },
        Telefones: ['81984711494'],
    },
]);