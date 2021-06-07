package Gui;
import javax.swing.JFrame;
import java.awt.event.*;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTabbedPane;
import java.sql.*;
import DB.DBConn;
public class MainGui extends JFrame implements WindowListener {
   static MainGui mainGui = null;
   Connection conn=null;
   public MainGui() {
      mainGui = this;
      MovieGui movieGui = new MovieGui(this);
      ReviewGui reviewGui = new ReviewGui(this);
      AdminGui adminGui = new AdminGui(this);

      setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
      JTabbedPane tPane = new JTabbedPane();
      
      JPanel p1 = new JPanel();
      JPanel p2 = new JPanel();
      JPanel p3 = new JPanel();

      tPane.addTab("영화 검색",movieGui.getMoviePanel());
      tPane.addTab("리뷰", reviewGui.getReviewPanel());
      tPane.addTab("관리자", adminGui.getAdminGui());
      this.add(tPane);
      this.setTitle("모두의 영화");
      this.setSize(500, 570);
      this.setVisible(true);
      this.addWindowListener(this);
   }
   public void windowActivated(WindowEvent e) {}
    public void windowClosed(WindowEvent e) {}
    public void windowClosing(WindowEvent e) {
       conn=DBConn.getConnection();
        try {
           if(conn!=null)
              conn.close();
      } catch (SQLException e1) {
         // TODO Auto-generated catch block
         e1.printStackTrace();
      }
        System.exit(0);
            
    }
    public void windowDeactivated(WindowEvent e) {}
    public void windowDeiconified(WindowEvent e) {}
    public void windowIconified(WindowEvent e) {}
    public void windowOpened(WindowEvent e) {}

}