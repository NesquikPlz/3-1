package DB;

import java.sql.*;
public class DBConn {
	private static Connection conn = null; //연결 시킨것을 여기다가 저장한다. 
	private DBConn () {};
	public static Connection getConnection() {
		if(conn==null) {
	        try{
	            //1. 드라이버 로딩 : mysql 드라이버 로딩
	           Class.forName("com.mysql.cj.jdbc.Driver"); 
	            //드라이버들이 읽히기만 하면 자동 객체가 생성되고 DriverManager에 등록된다.
	 
	            //2. mysql과 연결시키기
	            String url = "jdbc:mysql://localhost:3305/DB2021Team05?allowPublicKeyRetrieval=true";

	            conn = DriverManager.getConnection(url, "root", "humbug");
	            System.out.println("Successfully Connection!");
	        }
	 
	        catch(ClassNotFoundException e){
	            System.out.println("Failed because of not loading driver");
	        }
	        catch(SQLException e){
	            System.out.println("error : " + e);
	        }
		}
        return conn;
		
	}
}
