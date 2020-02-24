This project reads transaction data of customers and calculates reward points for them.

### PRE-REQUISITES
Docker

### INSTRUCTIONS
Run the following commands:

```
docker pull agarg145/reward_calculator
docker run -it agarg145/reward_calculator bash
chown -R mysql:mysql /var/lib/mysql /var/run/mysqld
service mysql start
cd /home/rewards_calculator/build && ./transferwise ../transactions.csv localhost archit password
```

#### To view the results in mysql

Run the following inside your docker container

```mysql -u archit -p```

Give "password" as the password when prompted.
```
use rewards;
select * from client_rewards;
```

#### To find your container id
`docker ps -a`

Grab the container id against our newly pulled image. 

#### To copy your own transactions file into docker container
```
docker cp {{LOCAL_FILE_PATH}} {{DOCKER_CONTAINER_ID}}:/home/rewards_calculator/

```

You can now run the executable with your file as input
