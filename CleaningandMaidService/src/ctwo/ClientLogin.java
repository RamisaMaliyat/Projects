/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package ctwo;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import javax.swing.JOptionPane;

/**
 *
 * @author Lenovo
 */
public class ClientLogin extends javax.swing.JFrame {

    /**
     * Creates new form ClientLogin
     */
    public ClientLogin() {
        initComponents();
          setLocationRelativeTo(null);
    }
    public Connection connection;
    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jLabel1 = new javax.swing.JLabel();
        ClientUserName = new javax.swing.JTextField();
        UserPassword = new javax.swing.JPasswordField();
        Save = new javax.swing.JButton();
        jLabel3 = new javax.swing.JLabel();
        Reset = new javax.swing.JButton();
        jLabel2 = new javax.swing.JLabel();
        jLabel4 = new javax.swing.JLabel();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        setMaximumSize(new java.awt.Dimension(1228, 820));
        setMinimumSize(new java.awt.Dimension(980, 850));
        setPreferredSize(new java.awt.Dimension(1000, 760));
        setResizable(false);
        getContentPane().setLayout(null);

        jLabel1.setFont(new java.awt.Font("Comic Sans MS", 3, 18)); // NOI18N
        jLabel1.setText("Password");
        getContentPane().add(jLabel1);
        jLabel1.setBounds(71, 292, 96, 44);
        getContentPane().add(ClientUserName);
        ClientUserName.setBounds(332, 221, 177, 42);
        getContentPane().add(UserPassword);
        UserPassword.setBounds(332, 296, 177, 41);

        Save.setFont(new java.awt.Font("Comic Sans MS", 3, 18)); // NOI18N
        Save.setText("sign in");
        Save.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                SaveActionPerformed(evt);
            }
        });
        getContentPane().add(Save);
        Save.setBounds(71, 409, 128, 60);

        jLabel3.setFont(new java.awt.Font("Comic Sans MS", 3, 18)); // NOI18N
        jLabel3.setText("CLientId");
        getContentPane().add(jLabel3);
        jLabel3.setBounds(71, 210, 128, 42);

        Reset.setFont(new java.awt.Font("Comic Sans MS", 3, 18)); // NOI18N
        Reset.setText("Reset");
        Reset.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                ResetActionPerformed(evt);
            }
        });
        getContentPane().add(Reset);
        Reset.setBounds(357, 409, 125, 60);

        jLabel2.setFont(new java.awt.Font("Comic Sans MS", 3, 24)); // NOI18N
        jLabel2.setText("Client Login Form");
        getContentPane().add(jLabel2);
        jLabel2.setBounds(467, 68, 254, 51);

        jLabel4.setIcon(new javax.swing.ImageIcon(getClass().getResource("/ctwo/bigstock-Cleaning-Concept-Of-Cleaning-S-271008463_1.jpg"))); // NOI18N
        jLabel4.setMaximumSize(new java.awt.Dimension(1228, 820));
        jLabel4.setMinimumSize(new java.awt.Dimension(1228, 820));
        getContentPane().add(jLabel4);
        jLabel4.setBounds(0, -60, 1000, 910);

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void SaveActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_SaveActionPerformed
        // TODO add your handling code here:
          
        try{
        Class.forName("com.microsoft.sqlserver.jdbc.SQLServerDriver");
              connection = DriverManager.getConnection(
                    "jdbc:sqlserver://localhost:1433;databaseName=checkpointnotwo;selectMethod=cursor", "sa", "123456");
            
           // int row = jTable_Display.getSelectedRow();
         //   String Value =(jTable_Display.getModel().getValueAt(row,0).toString());
            String query ="select * from Clientlogin where ClientId =? and UserPassword=?";          
             PreparedStatement pst = connection.prepareStatement(query);
         //   pst.setString(0, CstaffId.getText());
            pst.setString(1, ClientUserName.getText());
            pst.setString(2, UserPassword.getText());
            ResultSet rs = pst.executeQuery();
            if(rs.next())
            {
               JOptionPane.showMessageDialog(null,"ClientUserName and Password Matched"); 
               ClientOwn field = new ClientOwn(ClientUserName.getText(),UserPassword.getText());
               field .setVisible(true);
               setVisible(false);
               
            }
            
            else
            {
               JOptionPane.showMessageDialog(null, "ClientUserName and Password not Correct");
               
               ClientUserName.setText("");
               UserPassword.setText("");
            
            }
            connection.close();         
            
        }
        catch(Exception e)
        {
        
        JOptionPane.showMessageDialog(null, e);
        }
    }//GEN-LAST:event_SaveActionPerformed

    private void ResetActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_ResetActionPerformed
        // TODO add your handling code here:
         ClientUserName.setText("");
         UserPassword.setText("");
        
    }//GEN-LAST:event_ResetActionPerformed

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
            java.util.logging.Logger.getLogger(ClientLogin.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(ClientLogin.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(ClientLogin.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(ClientLogin.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new ClientLogin().setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JTextField ClientUserName;
    private javax.swing.JButton Reset;
    private javax.swing.JButton Save;
    private javax.swing.JPasswordField UserPassword;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JLabel jLabel2;
    private javax.swing.JLabel jLabel3;
    private javax.swing.JLabel jLabel4;
    // End of variables declaration//GEN-END:variables
}
