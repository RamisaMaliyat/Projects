/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package healthylifestyle;

import java.awt.Color;


public class menu extends javax.swing.JFrame {

    /**
     * Creates new form menu
     */
    public menu() {
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

        jMenu1 = new javax.swing.JMenu();
        jCheckBoxMenuItem1 = new javax.swing.JCheckBoxMenuItem();
        jToggleButton2 = new javax.swing.JToggleButton();
        jButton10 = new javax.swing.JButton();
        jLabel2 = new javax.swing.JLabel();
        jLabel1 = new javax.swing.JLabel();
        reminder = new javax.swing.JButton();
        weight_loss = new javax.swing.JButton();
        bmi = new javax.swing.JButton();
        food = new javax.swing.JButton();
        jButton1 = new javax.swing.JButton();
        jButton2 = new javax.swing.JButton();
        medicalinfo = new javax.swing.JButton();
        commontips2 = new javax.swing.JButton();
        commontips3 = new javax.swing.JButton();
        jLabel3 = new javax.swing.JLabel();
        jLabel4 = new javax.swing.JLabel();

        jMenu1.setText("jMenu1");

        jCheckBoxMenuItem1.setSelected(true);
        jCheckBoxMenuItem1.setText("jCheckBoxMenuItem1");

        jToggleButton2.setText("jToggleButton2");

        jButton10.setText("jButton10");

        jLabel2.setFont(new java.awt.Font("Tahoma", 0, 36)); // NOI18N
        jLabel2.setCursor(new java.awt.Cursor(java.awt.Cursor.DEFAULT_CURSOR));
        jLabel2.setMaximumSize(new java.awt.Dimension(1036, 869));
        jLabel2.setMinimumSize(new java.awt.Dimension(1036, 869));
        jLabel2.setPreferredSize(new java.awt.Dimension(1036, 869));

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        setCursor(new java.awt.Cursor(java.awt.Cursor.HAND_CURSOR));
        setMinimumSize(new java.awt.Dimension(980, 850));
        setResizable(false);
        getContentPane().setLayout(null);

        reminder.setBackground(new java.awt.Color(255, 255, 255));
        reminder.setFont(new java.awt.Font("Batang", 3, 18)); // NOI18N
        reminder.setText("Reminder");
        reminder.setMargin(new java.awt.Insets(0, 0, 0, 0));
        reminder.setOpaque(false);
        reminder.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                reminderActionPerformed(evt);
            }
        });
        getContentPane().add(reminder);
        reminder.setBounds(350, 440, 250, 50);

        weight_loss.setBackground(new java.awt.Color(255, 255, 255));
        weight_loss.setFont(new java.awt.Font("Batang", 3, 18)); // NOI18N
        weight_loss.setText("Weight Loss");
        weight_loss.setBorder(null);
        weight_loss.setMargin(new java.awt.Insets(0, 0, 0, 0));
        weight_loss.setOpaque(false);
        weight_loss.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                weight_lossActionPerformed(evt);
            }
        });
        getContentPane().add(weight_loss);
        weight_loss.setBounds(350, 290, 250, 50);

        bmi.setBackground(new java.awt.Color(255, 255, 255));
        bmi.setFont(new java.awt.Font("Batang", 3, 18)); // NOI18N
        bmi.setText("BMI & Tips");
        bmi.setMargin(new java.awt.Insets(0, 0, 0, 0));
        bmi.setOpaque(false);
        bmi.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                bmiActionPerformed(evt);
            }
        });
        getContentPane().add(bmi);
        bmi.setBounds(350, 240, 250, 50);

        food.setBackground(new java.awt.Color(255, 255, 255));
        food.setFont(new java.awt.Font("Batang", 3, 18)); // NOI18N
        food.setText("Food chart");
        food.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                foodActionPerformed(evt);
            }
        });
        getContentPane().add(food);
        food.setBounds(350, 190, 250, 50);

        jButton1.setBackground(new java.awt.Color(255, 255, 255));
        jButton1.setFont(new java.awt.Font("Batang", 3, 18)); // NOI18N
        jButton1.setText("Physical excercise");
        jButton1.setBorderPainted(false);
        jButton1.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton1ActionPerformed(evt);
            }
        });
        getContentPane().add(jButton1);
        jButton1.setBounds(350, 340, 250, 50);

        jButton2.setBackground(new java.awt.Color(255, 255, 255));
        jButton2.setFont(new java.awt.Font("Batang", 3, 18)); // NOI18N
        jButton2.setText("To Do List");
        jButton2.setBorderPainted(false);
        jButton2.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton2ActionPerformed(evt);
            }
        });
        getContentPane().add(jButton2);
        jButton2.setBounds(350, 490, 250, 50);

        medicalinfo.setBackground(new java.awt.Color(255, 255, 255));
        medicalinfo.setFont(new java.awt.Font("Batang", 3, 18)); // NOI18N
        medicalinfo.setText("Medical Information");
        medicalinfo.setBorder(null);
        medicalinfo.setMargin(new java.awt.Insets(0, 0, 0, 0));
        medicalinfo.setOpaque(false);
        medicalinfo.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                medicalinfoActionPerformed(evt);
            }
        });
        getContentPane().add(medicalinfo);
        medicalinfo.setBounds(350, 390, 250, 50);

        commontips2.setBackground(new java.awt.Color(255, 255, 255));
        commontips2.setFont(new java.awt.Font("Batang", 3, 18)); // NOI18N
        commontips2.setText("Weather based Tips");
        commontips2.setMargin(new java.awt.Insets(0, 0, 0, 0));
        commontips2.setOpaque(false);
        commontips2.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                commontips2ActionPerformed(evt);
            }
        });
        getContentPane().add(commontips2);
        commontips2.setBounds(350, 540, 250, 50);

        commontips3.setBackground(new java.awt.Color(255, 255, 255));
        commontips3.setFont(new java.awt.Font("Batang", 3, 18)); // NOI18N
        commontips3.setText("Common Tips");
        commontips3.setMargin(new java.awt.Insets(0, 0, 0, 0));
        commontips3.setOpaque(false);
        commontips3.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                commontips3ActionPerformed(evt);
            }
        });
        getContentPane().add(commontips3);
        commontips3.setBounds(350, 590, 250, 50);
        getContentPane().add(jLabel3);
        jLabel3.setBounds(0, 0, 0, 970);

        jLabel4.setIcon(new javax.swing.ImageIcon(getClass().getResource("/healthylifestyle/_cafcda04-1329-11e9-910e-2eacbc0579ab.jpg"))); // NOI18N
        getContentPane().add(jLabel4);
        jLabel4.setBounds(-340, -30, 1370, 930);

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void reminderActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_reminderActionPerformed
        // TODO add your handling code here:
         reminder cs=new reminder();
        cs.setVisible(true);
        new menu().setVisible(false);
        dispose();
    }//GEN-LAST:event_reminderActionPerformed

    private void weight_lossActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_weight_lossActionPerformed
       Weight_Loss_Process wlp=new Weight_Loss_Process();
       wlp.setVisible(true);
        new menu().setVisible(false);
        dispose();
    }//GEN-LAST:event_weight_lossActionPerformed

    private void bmiActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_bmiActionPerformed
        // TODO add your handling code here:
         newSubmit11 ns=new newSubmit11();
        ns.setVisible(true);
        new menu().setVisible(false);
          dispose();
    }//GEN-LAST:event_bmiActionPerformed

    private void foodActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_foodActionPerformed

        foodHabit f=new foodHabit();
        f.setVisible(true);
        new menu().setVisible(false);
        dispose();

    }//GEN-LAST:event_foodActionPerformed

    private void jButton1ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButton1ActionPerformed
        // TODO add your handling code here:
        PhysicalExercise p=new PhysicalExercise();
        p.setVisible(true);
        new menu().setVisible(false);
        dispose();
    }//GEN-LAST:event_jButton1ActionPerformed

    private void jButton2ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButton2ActionPerformed
        new menu().setVisible(false);
        dispose();
        weekly_todo_list wtd=new weekly_todo_list();
       wtd.setVisible(true);
    }//GEN-LAST:event_jButton2ActionPerformed

    private void medicalinfoActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_medicalinfoActionPerformed
         new menu().setVisible(false);
        dispose();
        Medical_Info m=new  Medical_Info();
        m.setVisible(true);
    }//GEN-LAST:event_medicalinfoActionPerformed

    private void commontips2ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_commontips2ActionPerformed
        // TODO add your handling code here:
         new menu().setVisible(false);
        dispose();
        weathertips m=new  weathertips();
        m.setVisible(true);
        
        
        
    }//GEN-LAST:event_commontips2ActionPerformed

    private void commontips3ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_commontips3ActionPerformed
        // TODO add your handling code here:
            new menu().setVisible(false);
        dispose();
        CommonTips m=new  CommonTips();
        m.setVisible(true);
        
    }//GEN-LAST:event_commontips3ActionPerformed

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
            java.util.logging.Logger.getLogger(menu.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(menu.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(menu.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(menu.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>
        //</editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new menu().setVisible(true);
            }
        });
    }

    private void setcolor(int i, int i0, int i1) {
        throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton bmi;
    private javax.swing.JButton commontips2;
    private javax.swing.JButton commontips3;
    private javax.swing.JButton food;
    private javax.swing.JButton jButton1;
    private javax.swing.JButton jButton10;
    private javax.swing.JButton jButton2;
    private javax.swing.JCheckBoxMenuItem jCheckBoxMenuItem1;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JLabel jLabel2;
    private javax.swing.JLabel jLabel3;
    private javax.swing.JLabel jLabel4;
    private javax.swing.JMenu jMenu1;
    private javax.swing.JToggleButton jToggleButton2;
    private javax.swing.JButton medicalinfo;
    private javax.swing.JButton reminder;
    private javax.swing.JButton weight_loss;
    // End of variables declaration//GEN-END:variables
}
