/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package healthylifestyle;

/**
 *
 * @author Lenovo
 */
public class weathertips extends javax.swing.JFrame {

    /**
     * Creates new form weathertips
     */
    public weathertips() {
        initComponents();
          setLocationRelativeTo(null);
         setTitle("  HEALTHY LIFESTYLE  ");
    }

    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jButton1 = new javax.swing.JButton();
        rainy = new javax.swing.JButton();
        winter = new javax.swing.JButton();
        summer = new javax.swing.JButton();
        jLabel1 = new javax.swing.JLabel();
        jLabel3 = new javax.swing.JLabel();
        jLabel2 = new javax.swing.JLabel();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        setMinimumSize(new java.awt.Dimension(980, 850));
        setResizable(false);
        getContentPane().setLayout(null);

        jButton1.setFont(new java.awt.Font("Comic Sans MS", 0, 15)); // NOI18N
        jButton1.setText("<back");
        jButton1.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton1ActionPerformed(evt);
            }
        });
        getContentPane().add(jButton1);
        jButton1.setBounds(60, 30, 100, 40);

        rainy.setFont(new java.awt.Font("Comic Sans MS", 0, 15)); // NOI18N
        rainy.setText("Rainy weatherTips");
        rainy.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                rainyActionPerformed(evt);
            }
        });
        getContentPane().add(rainy);
        rainy.setBounds(350, 340, 230, 60);

        winter.setFont(new java.awt.Font("Comic Sans MS", 0, 15)); // NOI18N
        winter.setText("Winter Tips ");
        winter.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                winterActionPerformed(evt);
            }
        });
        getContentPane().add(winter);
        winter.setBounds(350, 470, 230, 60);

        summer.setFont(new java.awt.Font("Comic Sans MS", 0, 15)); // NOI18N
        summer.setText("Summer Tips ");
        summer.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                summerActionPerformed(evt);
            }
        });
        getContentPane().add(summer);
        summer.setBounds(350, 220, 230, 60);

        jLabel1.setFont(new java.awt.Font("Comic Sans MS", 1, 18)); // NOI18N
        jLabel1.setForeground(new java.awt.Color(0, 51, 153));
        jLabel1.setText("      Weather based tips");
        getContentPane().add(jLabel1);
        jLabel1.setBounds(310, 30, 290, 70);
        getContentPane().add(jLabel3);
        jLabel3.setBounds(-740, -260, 0, 1070);

        jLabel2.setIcon(new javax.swing.ImageIcon(getClass().getResource("/healthylifestyle/rainbow-leto-summer-colorful-umbrella-zont-park-park-doroga.jpg"))); // NOI18N
        getContentPane().add(jLabel2);
        jLabel2.setBounds(-600, -150, 2790, 980);

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void summerActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_summerActionPerformed
        // TODO add your handling code here:
        new weathertips().setVisible(false);
        dispose();
        summer m=new  summer();
        m.setVisible(true);
    }//GEN-LAST:event_summerActionPerformed

    private void jButton1ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButton1ActionPerformed
        // TODO add your handling code here:
        
        
         menu m=new menu();
        m.setVisible(true);
          new weathertips().setVisible(false);
          dispose();
    }//GEN-LAST:event_jButton1ActionPerformed

    private void rainyActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_rainyActionPerformed
        // TODO add your handling code here:
         new weathertips().setVisible(false);
        dispose();
        rainytips m=new  rainytips();
        m.setVisible(true);
    }//GEN-LAST:event_rainyActionPerformed

    private void winterActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_winterActionPerformed
        // TODO add your handling code here:
         new weathertips().setVisible(false);
        dispose();
        WinterTips m=new  WinterTips();
        m.setVisible(true);
    }//GEN-LAST:event_winterActionPerformed

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
            java.util.logging.Logger.getLogger(weathertips.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(weathertips.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(weathertips.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(weathertips.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new weathertips().setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton jButton1;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JLabel jLabel2;
    private javax.swing.JLabel jLabel3;
    private javax.swing.JButton rainy;
    private javax.swing.JButton summer;
    private javax.swing.JButton winter;
    // End of variables declaration//GEN-END:variables
}
