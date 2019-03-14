package models;

import java.sql.*;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;

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


    public static List<Date> loadMoreDate(Connection conn) {
        List<Date> list = new ArrayList<Date>();
        try {
            String sqlUser = "SELECT date_format(r.date, '%Y-%m-%d') as r_date " +
                    "FROM  registration r  " +
                    "GROUP BY date_format(r.date, '%Y-%m-%d') " +
                    "HAVING count(*) > 1";
            PreparedStatement statement = conn.prepareStatement(sqlUser);
            ResultSet rs = statement.executeQuery();
            int i = 0;
            while(rs.next()) {
                list.add( i ++, rs.getDate("r_date"));
            }
        } catch(Exception e) { }
        return list;
    }

    public static List<User> loadMoreRoleRegistration(Connection conn) {
        List<User> list = new ArrayList<User>();
        try {
            String sqlUser = "SELECT u.id as u_id, u.login as u_login, count(*) as u_count FROM  registration r  INNER JOIN user u ON (r.user_id = u.id) GROUP BY u.id, u.login HAVING count(*) > 1  ORDER BY u.login";
            PreparedStatement statement = conn.prepareStatement(sqlUser);
            ResultSet rs = statement.executeQuery();
            int i = 0;
            while(rs.next()) {
                User u = new User();
                u.setId( rs.getInt("u_id")  );
                u.setLogin( rs.getString("u_login")  );
                u.setCountRegistrations( rs.getInt("u_count") );
                list.add( i ++, u);
            }
        } catch(Exception e) {

        }
        return list;
    }

    public static List<Registration> loadAllRegistration(Connection conn) {
        List<Registration> list = new ArrayList<Registration>();

        try {
                String sqlUser = "SELECT u.id as u_id, u.login as u_login, r.role as r_role," +
                        " r.date as r_date, r.id as r_id  " +
                        "FROM  registration r  " +
                        "INNER JOIN user u ON (r.user_id = u.id)" +
                        "ORDER BY r.id";
                PreparedStatement statement = conn.prepareStatement(sqlUser);
                ResultSet rs = statement.executeQuery();
                int i = 0;
                while(rs.next()) {
                    User u = new User();
                    u.setId( rs.getInt("u_id")  );
                    u.setLogin( rs.getString("u_login")  );
                    Registration r = new Registration();
                    r.setUser(u);
                    r.setDate(rs.getTimestamp("r_date"));
                    r.setRole(rs.getString("r_role"));
                    r.setId(rs.getInt("r_id"));
                    list.add( i ++, r);
                }
            } catch(Exception e) {

            }

        return list;
    }


    public static void persists(Connection conn, Registration model) throws Exception  {
        insert(conn, model);
    }

    public static void insert(Connection conn, Registration model) throws Exception {

        boolean autoCommit = false;
        try {

            autoCommit = conn.getAutoCommit();
            conn.setAutoCommit(false);

            persists(conn, model.getUser());

            //

            String sqlInsertUser = "Insert into registration (user_id, role, date) VALUES (?,?,?)";
            PreparedStatement statement = conn.prepareStatement(sqlInsertUser,
                    Statement.RETURN_GENERATED_KEYS);
            statement.setInt(1, model.getUser().getId());
            statement.setString(2, model.getRole());
            statement.setTimestamp(3, new java.sql.Timestamp(model.getDate().getTime()));
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


    /**
     * Load or create user
     * @param conn
     * @param model
     * @throws Exception
     */
    public static void persists(Connection conn, User model) throws Exception  {
        try {
            String sqlUser = "SELECT id, login FROM user WHERE login = ?";
            PreparedStatement statement = conn.prepareStatement(sqlUser);
            statement.setString(1, model.getLogin());
            ResultSet rs = statement.executeQuery();
            if(rs.next()) {
                model.setId( rs.getInt("id")  );
                model.setLogin( rs.getString("login")  );
            } else {
                insert(conn, model);
            }
        } catch(Exception e) {
            throw  e;
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
