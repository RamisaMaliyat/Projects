
package ctwo;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.Statement;
import javax.swing.JOptionPane;


public class AdminLogin extends javax.swing.JFrame {
private Connection con;
    private Statement st;
    private ResultSet rs;
    int loginapproval = 0;
    public AdminLogin() {
        initComponents();
         setLocationRelativeTo(null);
         
          try{
              Class.forName("com.microsoft.sqlserver.jdbc.SQLServerDriver");
       con=DriverManager.getConnection("jdbc:sqlserver://localhost:1433;databaseName=checkpointnotwo;selectMethod=cursor", "sa", "123456");
       st=con.createStatement();
    }catch(Exception e)
    {
        System.out.println(e);
    }
    }

    
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jLabel2 = new javax.swing.JLabel();
        jLabel3 = new javax.swing.JLabel();
        back_button = new javax.swing.JButton();
        jLabel1 = new javax.swing.JLabel();
        jPanel1 = new javax.swing.JPanel();
        username_tfld = new javax.swing.JTextField();
        password_tfld = new javax.swing.JTextField();
        login = new javax.swing.JButton();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        setMinimumSize(new java.awt.Dimension(1228, 780));
        setResizable(false);
        getContentPane().setLayout(null);

        jLabel2.setFont(new java.awt.Font("Arial Black", 0, 28)); // NOI18N
        jLabel2.setForeground(new java.awt.Color(255, 255, 255));
        jLabel2.setText("Cleaning & ");
        getContentPane().add(jLabel2);
        jLabel2.setBounds(20, 190, 210, 100);

        jLabel3.setFont(new java.awt.Font("Arial Black", 1, 28)); // NOI18N
        jLabel3.setForeground(new java.awt.Color(255, 255, 255));
        jLabel3.setText("Maid Service");
        getContentPane().add(jLabel3);
        jLabel3.setBounds(20, 280, 230, 60);

        back_button.setBackground(new java.awt.Color(255, 204, 0));
        back_button.setText("<<");
        back_button.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                back_buttonMouseClicked(evt);
            }
        });
        back_button.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                back_buttonActionPerformed(evt);
            }
        });
        getContentPane().add(back_button);
        back_button.setBounds(0, 0, 49, 23);

        jLabel1.setBackground(new java.awt.Color(255, 204, 0));
        jLabel1.setOpaque(true);
        getContentPane().add(jLabel1);
        jLabel1.setBounds(0, 0, 260, 760);

        jPanel1.setBackground(new java.awt.Color(255, 255, 255));

        username_tfld.setHorizontalAlignment(javax.swing.JTextField.CENTER);
        username_tfld.setText("Username");
        username_tfld.addFocusListener(new java.awt.event.FocusAdapter() {
            public void focusGained(java.awt.event.FocusEvent evt) {
                username_tfldFocusGained(evt);
            }
        });
        username_tfld.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                username_tfldActionPerformed(evt);
            }
        });

        password_tfld.setHorizontalAlignment(javax.swing.JTextField.CENTER);
        password_tfld.setText("password");

        login.setBackground(new java.awt.Color(255, 204, 51));
        login.setText("login");
        login.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                loginActionPerformed(evt);
            }
        });

        javax.swing.GroupLayout jPanel1Layout = new javax.swing.GroupLayout(jPanel1);
        jPanel1.setLayout(jPanel1Layout);
        jPanel1Layout.setHorizontalGroup(
            jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel1Layout.createSequentialGroup()
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(jPanel1Layout.createSequentialGroup()
                        .addGap(232, 232, 232)
                        .addComponent(username_tfld, javax.swing.GroupLayout.PREFERRED_SIZE, 352, javax.swing.GroupLayout.PREFERRED_SIZE))
                    .addGroup(jPanel1Layout.createSequentialGroup()
                        .addGap(336, 336, 336)
                        .addComponent(login, javax.swing.GroupLayout.PREFERRED_SIZE, 144, javax.swing.GroupLayout.PREFERRED_SIZE))
                    .addGroup(jPanel1Layout.createSequentialGroup()
                        .addGap(283, 283, 283)
                        .addComponent(password_tfld, javax.swing.GroupLayout.PREFERRED_SIZE, 255, javax.swing.GroupLayout.PREFERRED_SIZE)))
                .addContainerGap(426, Short.MAX_VALUE))
        );
        jPanel1Layout.setVerticalGroup(
            jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, jPanel1Layout.createSequentialGroup()
                .addGap(194, 194, 194)
                .addComponent(username_tfld, javax.swing.GroupLayout.PREFERRED_SIZE, 40, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(18, 18, 18)
                .addComponent(password_tfld, javax.swing.GroupLayout.PREFERRED_SIZE, 40, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(18, 18, 18)
                .addComponent(login)
                .addContainerGap(467, Short.MAX_VALUE))
        );

        getContentPane().add(jPanel1);
        jPanel1.setBounds(260, 0, 1010, 800);

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void username_tfldFocusGained(java.awt.event.FocusEvent evt) {//GEN-FIRST:event_username_tfldFocusGained

    }//GEN-LAST:event_username_tfldFocusGained

    private void loginActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_loginActionPerformed
        // TODO add your handling code here:
      String username = username_tfld.getText();
        String password = password_tfld.getText();
        if (username.isEmpty() || password.isEmpty())
            JOptionPane.showMessageDialog(null, "please give valid username and password");
        else {
            String query = "Select * FROM admin";
            try {
                rs = st.executeQuery(query);
                //     System.out.println("results from the query :");
                while (rs.next()) {
                    String uname = rs.getString("username");
                    String p = rs.getString("password");
                    System.out.println(uname + "   " + p);
                    if (username.equals(uname) && password.equals(p)) {
                        loginapproval = 1;
                        break;
                    }
                }
            } catch (Exception e) {
                System.out.println(e);
            }
           if (loginapproval == 1) {
                menu m = new menu();
                m.setVisible(true);
                new AdminLogin().setVisible(false);
                dispose();
            } else {
                JOptionPane.showMessageDialog(null, "this account does not exist");
            }
        
    }          
            
    }//GEN-LAST:event_loginActionPerformed

    private void back_buttonMouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_back_buttonMouseClicked
        // TODO add your handling code here:
    }//GEN-LAST:event_back_buttonMouseClicked

    private void back_buttonActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_back_buttonActionPerformed
        // TODO add your handling code here:
        start as=new start();
        as.setVisible(true);
        new AdminLogin().setVisible(false);
        dispose();
    }//GEN-LAST:event_back_buttonActionPerformed

    private void username_tfldActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_username_tfldActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_username_tfldActionPerformed
    
    /**
     * @param args the command line arguments
     */
    public static void main(String args[]) {
        /* Set the Nimbus look and feel */
        //<editor-fold defaultstate="collapsed" desc=" Look and feel setting code (optional) ">
        /* If Nimbus (introduced in Java SE 6) is not available, stay with the default look and feel.
         * For details see http://download.oracle.com/javase/tutorial/uiswing/lookandfeel/plaf.html 
         */
        try {
            for (javax.swing.UIManager.LookAndFeelInfo info : javax.swing.UIManager.getInstalledLookAndFeels()) {
                if ("Nimbus".equals(info.getName())) {
                    javax.swing.UIManager.setLookAndFeel(info.getClassName());
                    break;
                }
            }
        } catch (ClassNotFoundException ex) {
            java.util.logging.Logger.getLogger(AdminLogin.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(AdminLogin.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(AdminLogin.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(AdminLogin.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>
        //</editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new AdminLogin().setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton back_button;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JLabel jLabel2;
    private javax.swing.JLabel jLabel3;
    private javax.swing.JPanel jPanel1;
    private javax.swing.JButton login;
    private javax.swing.JTextField password_tfld;
    private javax.swing.JTextField username_tfld;
    // End of variables declaration//GEN-END:variables
}
