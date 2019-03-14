package models;

import java.sql.*;

public class Util {

    public static Connection getConnection()
            throws ClassNotFoundException, SQLException {
        String hostName = "localhost";
        String dbName = "test";
        String userName = "root";
        String password = "admin";
        return getMySQLConnection(hostName, dbName, userName, password);
    }

    public static Connection getMySQLConnection(String hostName, String dbName,
                                                String userName, String password) throws SQLException,
            ClassNotFoundException {

        Class.forName("com.mysql.jdbc.Driver");
        String connectionURL = "jdbc:mysql://" + hostName + ":3306/" + dbName;
        Connection conn = DriverManager.getConnection(connectionURL, userName,
                password);
        return conn;
    }

    public static void closeQuietly(Connection conn) {
        try {
            conn.close();
        } catch (Exception e) {
        }
    }

    public static void rollbackQuietly(Connection conn) {
        try {
            conn.rollback();
        } catch (Exception e) {
        }
    }


    public static void persists(Connection conn, Registration model) throws Exception  {
        insert(conn, model);
    }

    public static void insert(Connection conn, Registration model) throws Exception {

        boolean autoCommit = false;
        try {

            autoCommit = conn.getAutoCommit();
            conn.setAutoCommit(false);

            insert(conn, model.getUser());

            //

            String sqlInsertUser = "Insert into registration (user_id, role, date) VALUES (?,?,?)";
            PreparedStatement statement = conn.prepareStatement(sqlInsertUser,
                    Statement.RETURN_GENERATED_KEYS);
            statement.setInt(1, model.getUser().getId());
            statement.setString(2, model.getRole());
            statement.setDate(3, new java.sql.Date(model.getDate().getTime()));
            int affectedRows = statement.executeUpdate();

            if (affectedRows == 0) {
                throw new SQLException("Creating user failed, no rows affected.");
            }

            ResultSet generatedKeys = statement.getGeneratedKeys();
            if (generatedKeys.next()) {
                model.setId(generatedKeys.getInt(1));
            }  else {
                throw new SQLException("Creating user failed, no ID obtained.");
            }

            conn.commit();
        } catch (Exception e) {
            rollbackQuietly(conn);
            throw e;
        }finally {
            try {
                conn.setAutoCommit(autoCommit);
            } catch (SQLException e) {}
        }
    }

    public static void insert(Connection conn, User model) throws Exception {

        try {
            String sqlInsertUser = "Insert into user (login) VALUES (?)";
            PreparedStatement statement = conn.prepareStatement(sqlInsertUser,
                    Statement.RETURN_GENERATED_KEYS);
            statement.setString(1, model.getLogin());
            int affectedRows = statement.executeUpdate();

            if (affectedRows == 0) {
                throw new SQLException("Creating user failed, no rows affected.");
            }

            ResultSet generatedKeys = statement.getGeneratedKeys();
            if (generatedKeys.next()) {
                model.setId(generatedKeys.getInt(1));
            }  else {
                throw new SQLException("Creating user failed, no ID obtained.");
            }
        } catch (Exception e) {
            throw e;
        }
    }



    public static void createDataBase(Connection conn) throws Exception {

        boolean autoCommit = false;
        try {

            autoCommit = conn.getAutoCommit();
            conn.setAutoCommit(false);
            String sqlTable1 = "CREATE TABLE IF NOT EXISTS `user` ( " +
                "`id` int(11) unsigned NOT NULL AUTO_INCREMENT, " +
                "`login` varchar(8) NOT NULL, " +
                "PRIMARY KEY (`id`)" +
                " ) ENGINE=InnoDB DEFAULT CHARSET=utf8;";
            conn.prepareStatement(sqlTable1).execute();

            String sqlTable2 = "CREATE TABLE IF NOT EXISTS  `registration` ( " +
                    "`id` int(11) unsigned NOT NULL AUTO_INCREMENT, " +
                    "`user_id` int(11) unsigned NOT NULL, " +
                    "`role` varchar(16) NOT NULL, " +
                    "`date` timestamp NOT NULL, " +
                    "PRIMARY KEY (`id`)," +
                    "FOREIGN KEY(user_id) REFERENCES user(`id`)" +
                    " ) ENGINE=InnoDB DEFAULT CHARSET=utf8;";
            conn.prepareStatement(sqlTable2).execute();

            conn.commit();
        } catch (Exception e) {
            rollbackQuietly(conn);
            throw e;
        } finally {
            try {
                conn.setAutoCommit(autoCommit);
            } catch (SQLException e) {}
        }

    }

}
