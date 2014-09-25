clear
load('two_electrons.mat')
xmax = 14;

%omega_r = 0.01
subplot(4,1,1) 
hold on
plot(rho,V*0.5e-2,'g--','LineWidth',3)
plot(rho,psi_0.^2,'b-','LineWidth',2)
plot(rho,psi_1.^2,'m-','LineWidth',2)
plot(rho,psi_2.^2,'r-','LineWidth',2)
axis([0,xmax,0,max(psi_0.^2)]);
xlabel('rho');
ylabel(' omega_r = 0.01')

subplot(4,1,2) 
hold on
plot(rho,V1*0.5e-2,'g--','LineWidth',3)
plot(rho,psi_200.^2,'b-','LineWidth',2)
plot(rho,psi_201.^2,'m-','LineWidth',2)
plot(rho,psi_202.^2,'r-','LineWidth',2)
axis([0,xmax,0,max(psi_200.^2)]);
xlabel('rho');
ylabel(' omega_r = 0.5')



subplot(4,1,3) 
hold on
plot(rho,V2*0.5e-2,'g--','LineWidth',3)
plot(rho,psi_400.^2,'b-','LineWidth',2)
plot(rho,psi_401.^2,'m-','LineWidth',2)
plot(rho,psi_402.^2,'r-','LineWidth',2)
axis([0,xmax,0,max(psi_400.^2)]);
xlabel('rho');
ylabel(' omega_r = 1')


subplot(4,1,4) 
hold on
plot(rho,V3*0.5e-2,'g--','LineWidth',3)
plot(rho,psi_600.^2,'b-','LineWidth',2)
plot(rho,psi_601.^2,'m-','LineWidth',2)
plot(rho,psi_602.^2,'r-','LineWidth',2)
axis([0,xmax,0,max(psi_600.^2)]);
xlabel('rho');
ylabel(' omega_r = 5')
legend('Potential(not to scale)','(psi_0)^2','(psi_1)^2','(psi_3)^2')
