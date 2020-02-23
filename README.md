# TODO
These are the things yet to be done.
1. Ship the my sql connector library with the code, so that the client does not have to install it.
2. Write an integration test.
3. Add everything into a docker container so that the client doesnt have to install myqsl server as well.

# PRE-REQUISITES
cmake
Mysql server
mysql-connector-c++-8.0.18 - cpp connector library for mysql

# MYSQL SERVER SETUP INSTRUCTIONS
1. Setup mysql server on your machine.
2. Execute the instruction given in db_config/db commands to set up the database.

# MYSQL CONNECTOR LIBRARY SETUP
1. Install mysql connector library for your os from https://dev.mysql.com/downloads/connector/cpp/.
2. Set environment variable MYSQL_CONNECTOR_INSTALL_DIR equal to the install location of the connector lib. You can do that using the export command eg.
    "export MYSQL_CONNECTOR_INSTALL_DIR=/usr/local/mysql-connector-c++-8.0.18"

# BUILD INSTRUCTIONS
1. Run "git clone https://github.com/arctgarg/rewards_calculator.git" to clone this repo.
2. cd rewards_calculator.
3. mkdir build && cd build.
4. cmake ../. && make clean all test install.

# MAC OS SPECIFIC SETTING
If on mac, you would need to set an additional environment variable called DYLD_LIBRARY_PATH.
Run "export DYLD_LIBRARY_PATH=${MYSQL_CONNECTOR_INSTALL_DIR}/lib64".

You may need to do similar setup for other operating systems as well.

Once you have the binary ready, either from the above build steps or from the pre-build zip file, you can run the executable via
"./transferwise {{TRANSACTION_FILE_PATH}} {{DB_HOSTNAME}} {{DB_USERNAME}} {{DB_PASSWORD}}". Example: "./transferwise ../transactions.csv localhost root root"

The output is printed on the command line, and also updated in the database.

