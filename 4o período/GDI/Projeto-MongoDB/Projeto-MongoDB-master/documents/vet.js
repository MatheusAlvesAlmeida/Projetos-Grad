db.vet.insertMany([
    {
        _id: 0,
        CPF: '03176487532',
        Nome: 'Ricardo',
        Endereço: {
            descrição: 'Alameda das Araras',
            cep: '56800000', 
            cidade: 'Recife'
        },
        CRMV: '12701',
        Especialidade: ['cachorro', 'gato']
    },
    {
        _id: 1,
        CPF: '03178903746',
        Nome: 'Beatriz',
        Endereço: {
            descrição: 'Rua Piranhas',
            cep: '50620491', 
            cidade: 'Pesqueira'
        },
        CRMV: '40644',
        Especialidade: ['cachorro', 'gato']
    },
    {
        _id: 2,
        CPF: '58961248956',
        Nome: 'Astolfo',
        Endereço: {
            descrição: 'Travessa das Dores',
            cep: '50660240', 
            cidade: 'Olinda'
        },
        CRMV: '23865',
        Especialidade: ['roedor']
    },
    {
        _id: 3,
        CPF: '03186390274',
        Nome: 'Laura',
        Endereço: {
            descrição: 'Rua da Federal',
            cep: '54440020', 
            cidade: 'Recife'
        },
        CRMV: '45858',
        Especialidade: ['réptil']
    },
]);