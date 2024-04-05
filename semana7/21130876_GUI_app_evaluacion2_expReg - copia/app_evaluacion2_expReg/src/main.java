
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class main extends javax.swing.JFrame {

    String expReg = REGEX;
    String cad = INPUT;
    //expresion regular -> delimita con \b y busca la palabra 'cat'
    private static final String REGEX = "\\bcat\\b";
    //cadena de texto de entrada
    private static final String INPUT = "cat cat cat cattie cat";

    public main() {
        initComponents();

        jLabel_regex.setText("Expresion actual: " + expReg);
        jTextField_cadena.setText(cad);
    }

    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jLabel1 = new javax.swing.JLabel();
        jLabel_regex = new javax.swing.JLabel();
        jTextField_cadena = new javax.swing.JTextField();
        jLabel3 = new javax.swing.JLabel();
        jButton_comprobar = new javax.swing.JButton();
        jScrollPane1 = new javax.swing.JScrollPane();
        jTextArea_res = new javax.swing.JTextArea();
        jTextField_regex = new javax.swing.JTextField();
        jButton_cambiar = new javax.swing.JButton();
        jLabel2 = new javax.swing.JLabel();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        setTitle("21130876");
        setName("21130876"); // NOI18N

        jLabel1.setFont(new java.awt.Font("Trebuchet MS", 1, 18)); // NOI18N
        jLabel1.setText("EXPRESIONES REGULARES");

        jLabel_regex.setText("Expresion actual:");

        jTextField_cadena.setToolTipText("");
        jTextField_cadena.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jTextField_cadenaActionPerformed(evt);
            }
        });

        jLabel3.setText("Cadena:");

        jButton_comprobar.setText("comprobar");
        jButton_comprobar.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton_comprobarActionPerformed(evt);
            }
        });

        jTextArea_res.setEditable(false);
        jTextArea_res.setColumns(20);
        jTextArea_res.setRows(5);
        jScrollPane1.setViewportView(jTextArea_res);

        jTextField_regex.setToolTipText("");
        jTextField_regex.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jTextField_regexActionPerformed(evt);
            }
        });

        jButton_cambiar.setText("cambiar");
        jButton_cambiar.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton_cambiarActionPerformed(evt);
            }
        });

        jLabel2.setText("Expresion regular:");

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addGap(90, 90, 90)
                .addComponent(jLabel1)
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
            .addGroup(layout.createSequentialGroup()
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, layout.createSequentialGroup()
                        .addGap(0, 0, Short.MAX_VALUE)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, layout.createSequentialGroup()
                                .addComponent(jButton_comprobar)
                                .addGap(49, 49, 49))
                            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, layout.createSequentialGroup()
                                .addComponent(jTextField_cadena, javax.swing.GroupLayout.PREFERRED_SIZE, 135, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addGap(18, 18, 18))))
                    .addGroup(layout.createSequentialGroup()
                        .addContainerGap()
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addGroup(layout.createSequentialGroup()
                                .addComponent(jLabel_regex)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, layout.createSequentialGroup()
                                .addComponent(jLabel2)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                                .addComponent(jTextField_regex, javax.swing.GroupLayout.PREFERRED_SIZE, 90, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addGap(18, 18, 18))
                            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, layout.createSequentialGroup()
                                .addGap(0, 0, Short.MAX_VALUE)
                                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                    .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, layout.createSequentialGroup()
                                        .addComponent(jLabel3)
                                        .addGap(65, 65, 65))
                                    .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, layout.createSequentialGroup()
                                        .addComponent(jButton_cambiar)
                                        .addGap(52, 52, 52)))))))
                .addComponent(jScrollPane1, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addContainerGap())
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addGap(30, 30, 30)
                .addComponent(jLabel1)
                .addGap(18, 18, 18)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(layout.createSequentialGroup()
                        .addComponent(jScrollPane1, javax.swing.GroupLayout.PREFERRED_SIZE, 210, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                    .addGroup(layout.createSequentialGroup()
                        .addComponent(jLabel_regex)
                        .addGap(18, 18, 18)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                            .addComponent(jTextField_regex, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                            .addComponent(jLabel2))
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                        .addComponent(jButton_cambiar)
                        .addGap(13, 13, 13)
                        .addComponent(jLabel3)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                        .addComponent(jTextField_cadena, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                        .addComponent(jButton_comprobar)
                        .addGap(59, 59, 59))))
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void jTextField_cadenaActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jTextField_cadenaActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_jTextField_cadenaActionPerformed

    private void jButton_comprobarActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButton_comprobarActionPerformed
        // TODO add your handling code here:
        //LUIS BARRANCO 21130876
        StringBuilder res = new StringBuilder(" ");

        cad = jTextField_cadena.getText();


        Pattern p = Pattern.compile(expReg); // expresion regular asignada
        Matcher m = p.matcher(cad);   // get a matcher object
        int count = 0; // creamos e inicializamos contador

        while (m.find()) {
            //va mostrando la posicion de inicio y fin de donde se encuentra 
            //la palabra que cumple la condicion
            //ademas cuenta el numero de palabras que coinciden
            count++;
            res.append("COINCIDE!!\n");
            System.out.println("Match number " + count);
            res.append("Match number " + count + "\n");
            System.out.println("start(): " + m.start());
            res.append("start(): " + m.start() + "\n");
            System.out.println("end(): " + m.end());
            res.append("end(): " + m.end() + "\n");

            jTextArea_res.setText(res.toString());
        }
    }//GEN-LAST:event_jButton_comprobarActionPerformed

    private void jTextField_regexActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jTextField_regexActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_jTextField_regexActionPerformed

    private void jButton_cambiarActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButton_cambiarActionPerformed
        // TODO add your handling code here:
        expReg = jTextField_regex.getText();
        jLabel_regex.setText("Expresion actual: " + expReg);
    }//GEN-LAST:event_jButton_cambiarActionPerformed

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
            java.util.logging.Logger.getLogger(main.class
                    .getName()).log(java.util.logging.Level.SEVERE, null, ex);

        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(main.class
                    .getName()).log(java.util.logging.Level.SEVERE, null, ex);

        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(main.class
                    .getName()).log(java.util.logging.Level.SEVERE, null, ex);

        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(main.class
                    .getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new main().setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton jButton_cambiar;
    private javax.swing.JButton jButton_comprobar;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JLabel jLabel2;
    private javax.swing.JLabel jLabel3;
    private javax.swing.JLabel jLabel_regex;
    private javax.swing.JScrollPane jScrollPane1;
    private javax.swing.JTextArea jTextArea_res;
    private javax.swing.JTextField jTextField_cadena;
    private javax.swing.JTextField jTextField_regex;
    // End of variables declaration//GEN-END:variables
}
