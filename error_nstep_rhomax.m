open('error_nstep_rhomax.mat');

%E0
subplot(1,3,1)
ylabel('Error E0')
xlabel('n_{step}')
error = abs(rho_max1_E0-E0);
rho1 = semilogy(n_step,error);
set(rho1,'Color',[1 0 0],'linewidth',2)
hold on;

error = abs(rho_max6_E0-E0);
rho6 = semilogy(n_step,error);
set(rho6,'Color',[0.75 0 0.25],'linewidth',2)

error = abs(rho_max11_E0-E0);
rho11 = semilogy(n_step,error);
set(rho11,'Color',[0.55 0 0.45],'linewidth',2)

error = abs(rho_max16_E0-E0);
rho16 = semilogy(n_step,error)
set(rho16,'Color',[0.35 0 0.65],'linewidth',2)

error = abs(rho_max21_E0-E0);
rho21 = semilogy(n_step,error,'k');
set(rho21,'Color',[0 0 1],'linewidth',2)

%E1
subplot(1,3,2)
ylabel('Error E1')
xlabel('n_{step}')
error = abs(rho_max1_E1-E_1);
rho1 = semilogy(n_step,error);
set(rho1,'Color',[1 0 0],'linewidth',2)
hold on;

error = abs(rho_max6_E1-E_1);
rho6 = semilogy(n_step,error);
set(rho6,'Color',[0.75 0 0.25],'linewidth',2)

error = abs(rho_max11_E1-E_1);
rho11 = semilogy(n_step,error);
set(rho11,'Color',[0.55 0 0.45],'linewidth',2)

error = abs(rho_max16_E1-E_1);
rho16 = semilogy(n_step,error)
set(rho16,'Color',[0.35 0 0.65],'linewidth',2)

error = abs(rho_max21_E1-E_1);
rho21 = semilogy(n_step,error,'k');
set(rho21,'Color',[0 0 1],'linewidth',2)

%E2
subplot(1,3,3)
ylabel('Error E2')
xlabel('n_{step}')
error = abs(rho_max1_E2-E_2);
rho1 = semilogy(n_step,error);
set(rho1,'Color',[1 0 0],'linewidth',2)
hold on;

error = abs(rho_max6_E2-E_2);
rho6 = semilogy(n_step,error);
set(rho6,'Color',[0.75 0 0.25],'linewidth',2)

error = abs(rho_max11_E2-E_2);
rho11 = semilogy(n_step,error);
set(rho11,'Color',[0.55 0 0.45],'linewidth',2)

error = abs(rho_max16_E2-E_2);
rho16 = semilogy(n_step,error)
set(rho16,'Color',[0.35 0 0.65],'linewidth',2)

error = abs(rho_max21_E2-E_2);
rho21 = semilogy(n_step,error,'k');
set(rho21,'Color',[0 0 1],'linewidth',2)

legend('rho_{max}=1','rho_{max}=6','rho_{max}=11','rho_{max}=16','rho_{max}=21')