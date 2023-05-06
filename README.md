100 Million Small Target
    "100 Million Small Target" is a business and life simulation game. 
    Starting from the age of 20, all choices are up to you, whether to become rich or poor.
  
1. Author Information:
    Guan Haoning -- GuanHaoNing
    Huang Zixuan -- HHuangZZixuan
    Qiao Lechong -- QDVLVI
    Ding Jiayi   -- daisyyding
    Zhu Jiaying  -- jytiff

2. Description
    At the age of 20, you enter society and try to achieve the small target of earning one billion before retirement.
    Buy and sell bitcoins, domain names, liquor, counterfeit mobile phones...
    Found a gaming company, a real estate company, an electrical manufacturing factory...
    Spend money on luxury homes, cars...
    This is a lifetime of ups and downs in the business world, and also a reflection of the times.
    When each wave of wealth comes, some people soar to great heights, some people work hard, and some people lose everything.
    Randomly born, but equal opportunities. The choice is in your own hands.

3. Rules
    Game objective: Get rich before retirement, for example, earn one billion first.
    Market: Choose items to buy/sell, buy low and sell high, expand warehouse, and accumulate capital.
    Entrepreneurship: Found a company, enjoy the appreciation of assets, and receive dividend income. A large investment is required to start a business, which can be increased or decreased later.
    Spend money: Buy cars and houses, consume in different places, change attributes.

4. Features
   I. FIVE requirements:
    (1) Generation of random game sets or events:
        - Randomly generate prices for buying/selling items.
        - Randomly generated 5 items appearing each year.
    (2) Data structures for storing game status:
        - Linked lists are used to store elements that are dynamically added or removed from our game status. For example, the goods inforation in storehouse.cpp. 
        - An array is also a simple data structure that are used to store our game status.
    (3) Dynamic memory management:
        - Goods and company information stored in linked list( pointers & dynamic variable allocation:```new```,```delete```)
        - Map(container) used in market.cpp
    (4) File input/output (e.g., for loading/saving game status):
        - ifstream used for getting information of player,company,storehouse
        - information of playere,company,storehouse is saved in separate files using ofstream defined in function.
    (5) Program codes in multiple files:
        - Different functions are in multiple files, i.e. business,market,spend_money.
        - Structs and classes are declared and stored in separate files.

  II. Functionality and special features:
        Players can not only earn money, but also set up companies and spend money, for example, to buy a house, a car or a lottery ticket.
        At the same time, it is possible to extend the retirement age when making consumption.
  
  III. Coding style:
        - Define each part in different functions to make it easier to apply and read.
        - Name functions and variables according to the parts they are associated with to optimize readibility.
       
5. Compilation and execution instructions
   Run ```make target``` to compile the game.
   Do ```./target``` to start the game.
   Run ```make clean``` to clean all the generated filles.

